/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:02:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/08 19:01:18 by mnunnari         ###   ########.fr       */
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

static void	get_quoted(char *str, char quot, char **ptr)
{
	char			*tmp;

	tmp = ft_strsub(str, 0, ft_strchr(str, quot) - str);
	ft_strcpy(*ptr, tmp);
	*ptr += ft_strlen(tmp);
	free(tmp);
}

static int	process_str(char **str, char *ptr)
{
	char			quot;

	while (**str)
	{
		//ft_printfnl("debug %c", **str);
		if ((quot = is_quote(**str)))
		{
			*str += 1;
			if (!ft_strchr(*str, quot))
				return (missing(quot));
			else
				get_quoted(*str, quot, &ptr);
			*str = ft_strchr(*str, quot) + 1;
			if (**str == ' ')
				return (1);
			else
				continue;
		}
		if (**str == ' ')
			return (1);
		*ptr++ = **str;
		*str += 1;
	}
	return (1);
}

int		get_next_tok(char **str, char **arg)
{
	char			*ptr;

	while (**str && **str == ' ')
		*str += 1;
	if (**str == '\0')
		return (0);
	*arg = ft_strnew((ft_strlen(*str) + 1));
	ptr = *arg;
	return (process_str(str, ptr));
}
