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

char			is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (c);
	return (0);
}

int				indexes(char *str, int *i, int *j)
{
	char			quot;

	if ((quot = is_quote(str[*i])))
	{
		*i = *i + 1;
		*j = *i;
		while (str[*i] && str[*i] != quot)
			*i = *i + 1;
		if (str[*i] == '\0')
		{
			ft_putendl("Missing quote");
			*i = 0;
			return (0);
		}
	}
	else
	{
		*j = *i;
		while (str[*i] && str[*i] != ' ')
			*i = *i + 1;
	}
	return (1);
}

int				get_next_tok(char *str, char **arg)
{
	static int		i;
	int				j;

	ft_putendl("debug");
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
	{
		i = 0;
		return (0);
	}
	j = 0;
	if (!indexes(str, &i, &j))
		return (-1);
	*arg = ft_strsub(str, j, i - j);
	i++;
	return (1);
}
