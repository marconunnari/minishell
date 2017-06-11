/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:51:43 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 05:54:53 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_envar(char *var, char **env)
{
	int		varlen;

	varlen = ft_strlen(var);
	while (*env)
	{
		if (ft_strnequ(var, *env, varlen))
			return (&((*env)[varlen + 1]));
		env++;
	}
	return (NULL);
}
