/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:02:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/28 15:34:45 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

static int	is_terminator(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

static int	missing(char c)
{
	ft_printfnl("Unmatched %c", c);
	return (-1);
}

static void	totok(char **tok, char *piece)
{
	char	*tmp;

	tmp = *tok;
	*tok = ft_strjoin(tmp, piece);
	free(tmp);
}

static int	take_string(char *ptr1, char *ptr2, char **env, char **tok)
{
	char		*envar;
	char		*ptr3;
	char		*ptr4;
	int		quoted;

	quoted = 1;
	if (ptr2)
	{
		quoted = *ptr2 == '\"' || *ptr2 == '\'';
		*ptr2 = '\0';
	}
	if (!quoted && *ptr1 == '~')
	{
		if (ptr1[1] == '\0')
		{
			envar = get_envar("HOME", env);
			return (take_string(envar, NULL, NULL, tok));
		}
		if (ptr1[1] == '/')
		{
			envar = get_envar("HOME", env);
			take_string(envar, NULL, NULL, tok);
			return (take_string(ptr1 + 1, NULL, env, tok));
		}
	}
	if (env && (ptr3 = ft_strchr(ptr1, '$')))
	{
		if (ptr3 > ptr1)
			take_string(ptr1, ptr3, env, tok);
		*ptr3 = '$';
		if ((ptr4 = ft_strchr(ptr3, '/')))
		{
			if (!take_string(ptr3, ptr4, env, tok))
				return (0);
			*ptr4 = '/';
			ptr1 = ptr4;
		}
		else
		{
			envar = get_envar(ptr3 + 1, env);
			ptr1 = envar;
		}
	}
	if (!ptr1)
		return (0);
	totok(tok, ptr1);
	return (1);
}

static int	null_tok(char *ptr, char **str)
{
	*str = ptr + 1;
	return (2);
}

static int	process_str(char **str, char **tok, char **env)
{
	char	*ptr1;
	char	*ptr2;
	char	quot;

	while (1)
	{
		ptr1 = ft_strchrs(*str, is_quote);
		ptr2 = ft_strchrs(*str, is_terminator);
		if (!ptr1 || ptr2 < ptr1)
			break ;
		quot = *ptr1;
		if (ptr1 > *str)
		{
			if (!take_string(*str, ptr1, env, tok))
				return (null_tok(ptr1, str));
			*str = ptr1 + 1;
		}
		ptr2 = ft_strchr(ptr1 + 1, quot);
		if (!ptr2 || (*ptr2 != quot))
			return (missing(quot));
		if (!take_string(ptr1 + 1, ptr2, *ptr1 == '\'' ? NULL : env, tok))
			return (null_tok(ptr2, str));
		*str = ptr2 + 1;
	}
	if (!take_string(*str, ptr2, env, tok))
		return (null_tok(ptr2, str));
	*str = ptr2 + 1;
	return (1);
}

int			get_next_tok(char **str, char **tok, char **env)
{
	while (**str && (**str == ' ' || **str == '\t') )
		*str += 1;
	if (**str == '\0')
		return (0);
	*tok = ft_strnew(0);
	return (process_str(str, tok, env));
}
