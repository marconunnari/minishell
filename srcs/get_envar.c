/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:51:43 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/13 20:42:06 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_envar(char *var, char **env)
{
	int		varlen;
	char	*varname;

	varlen = ft_strlen(var);
	while (*env)
	{
		varname = ft_strsub(*env, 0, ft_strchr(*env, '=') - *env);
		if (ft_strequ(var, varname))
			return (&((*env)[varlen + 1]));
		env++;
		free(varname);
	}
	return (NULL);
}
