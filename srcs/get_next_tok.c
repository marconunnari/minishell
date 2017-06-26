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

static int	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}

static int	missing(char c)
{
	ft_printfnl("Unmatched %c", c);
	return (-1);
}

static int	process_str(char **str, char **tok, char **env)
{
}

int		get_next_tok(char **str, char **tok, char **env)
{
	while (**str && **str == ' ')
		*str += 1;
	if (**str == '\0')
		return (0);
	*tok = ft_strnew(0);
	return (process_str(str, tok, env));
}
