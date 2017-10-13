/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 19:38:17 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/13 19:38:40 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	totok(char **tok, char *piece)
{
	char	*tmp;

	tmp = *tok;
	*tok = ft_strjoin(tmp, piece);
	free(tmp);
}

int			take_string(char *ptr1, char *ptr2, char **env, char **tok)
{
	char		*envar;
	char		*ptr3;
	char		*ptr4;
	int			quoted;

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
