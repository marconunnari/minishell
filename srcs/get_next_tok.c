/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:02:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/13 22:50:37 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (c);
	return (0);
}

static int	missing(char c)
{
	ft_printfnl("Unmatched %c", c);
	return (-1);
}

static void	get_quoted(char *str, char quot, char **arg, int *i, char **env)
{
	char			*tmp;
	char			*var;
	char			*newarg;

	tmp = ft_strsub(str, 0, ft_strchr(str, quot) - str);
	if (quot == '\"' && tmp[0] == '$' && tmp[1])
	{
		var = get_envar(&tmp[1], env);
		newarg = ft_strnew(ft_strlen(*arg) + ft_strlen(var) + ft_strlen(str) + 1);
		ft_strcpy(newarg, *arg);
		ft_strcpy(&newarg[ft_strlen(*arg)], var);
		free(*arg);
		*arg = newarg;
		*i += ft_strlen(var);
	}
	else
	{
		ft_strcpy(&(arg[0][*i]), tmp);
		*i += ft_strlen(tmp);
	}
	free(tmp);
}

static int	process_str(char **str, char **arg, char **env)
{
	char			quot;
	int				i;

	i = 0;
	while (**str)
	{
		if ((quot = is_quote(**str)))
		{
			*str += 1;
			if (!ft_strchr(*str, quot))
				return (missing(quot));
			else
				get_quoted(*str, quot, arg, &i, env);
			*str = ft_strchr(*str, quot) + 1;
			if (**str == ' ')
				return (1);
			else
				continue;
		}
		if (**str == ' ')
			return (1);
		arg[0][i++] = **str;
		*str += 1;
	}
	return (1);
}

int		get_next_tok(char **str, char **arg, char **env)
{
	(void)env;
	while (**str && **str == ' ')
		*str += 1;
	if (**str == '\0')
		return (0);
	*arg = ft_strnew((ft_strlen(*str) + 1));
	return (process_str(str, arg, env));
}
