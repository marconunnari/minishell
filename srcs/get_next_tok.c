/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:02:30 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/13 19:40:25 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_next_tok(char **str, char **tok, char **env)
{
	while (**str && (**str == ' ' || **str == '\t'))
		*str += 1;
	if (**str == '\0')
		return (0);
	*tok = ft_strnew(0);
	return (process_str(str, tok, env));
}
