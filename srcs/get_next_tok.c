/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:02:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/26 22:56:12 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

static int	is_terminator(char c)
{
	return (c == ' ' || c == '\0');
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

	if (ptr2)
		*ptr2 = '\0';
	else
		ptr2 = ptr1 + ft_strlen(ptr1) - 1;
	if (env && (ptr3 = ft_strchr(ptr1, '$')))
	{
		if (ptr3 > ptr1)
			take_string(ptr1, ptr3, env, tok);
		envar = get_envar(ptr3 + 1, env);
		if (!envar)
			ft_printfnl("%s: Undefined variable.", ptr3 + 1);
		ptr1 = envar;
	}
	if (!ptr1)
		return (0);
	totok(tok, ptr1);
	return (1);
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
				return (-1);
			*str = ptr1 + 1;
		}
		ptr2 = ft_strchr(ptr1 + 1, quot);
		if (!ptr2 || (*ptr2 != quot))
			return (missing(quot));
		if (!take_string(ptr1 + 1, ptr2, *ptr1 == '\'' ? NULL : env, tok))
			return (-1);
		*str = ptr2 + 1;
	}
	if (!take_string(*str, ptr2, env, tok))
		return (-1);
	*str = ptr2 + 1;
	return (1);
}

int			get_next_tok(char **str, char **tok, char **env)
{
	while (**str && **str == ' ')
		*str += 1;
	if (**str == '\0')
		return (0);
	*tok = ft_strnew(0);
	return (process_str(str, tok, env));
}
