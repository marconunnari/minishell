/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:39:36 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/13 19:39:39 by mnunnari         ###   ########.fr       */
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

static int	null_tok(char *ptr, char **str)
{
	*str = ptr + 1;
	return (2);
}

int			process_str(char **str, char **tok, char **env)
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
