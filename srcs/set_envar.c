/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 07:58:59 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 09:45:06 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**delete_envar(char *var, char **env)
{
	size_t		oldlen;
	size_t		i;
	char		**newenv;

	oldlen = ft_arrlen((void**)env);
	newenv = (char**)malloc(sizeof(char*) * (oldlen + 1));
	i = 0;
	while (*env)
	{
		if (!ft_strnequ(var, *env, ft_strchr(*env, '=') - *env))
		{
			newenv[i] = ft_strdup(*env);
			i++;
		}
		env++;
	}
	newenv[i] = NULL;
	return (newenv);
}

char			**update_envar(char *var, char *val, char **env)
{
	size_t		oldlen;
	size_t		i;
	char		**newenv;
	char		*newvar;

	oldlen = ft_arrlen((void**)env);
	newenv = (char**)malloc(sizeof(char*) * (oldlen + 1));
	newvar = ft_strnew(ft_strlen(var) + ft_strlen(val) + 2);
	ft_strcat(newvar, var);
	ft_strcat(newvar, "=");
	ft_strcat(newvar, val);
	i = 0;
	while (env[i])
	{
		if (ft_strnequ(var, env[i], ft_strchr(env[i], '=') - env[i]))
			newenv[i] = newvar;
		else
			newenv[i] = ft_strdup(env[i]);
		i++;
	}
	newenv[i] = NULL;
	return (newenv);
}

char			**create_envar(char *var, char *val, char **env)
{
	size_t		oldlen;
	size_t		i;
	char		**newenv;
	char		*newvar;

	oldlen = ft_arrlen((void**)env);
	newenv = (char**)malloc(sizeof(char*) * (oldlen + 2));
	i = 0;
	while (env[i])
	{
		newenv[i] = ft_strdup(env[i]);
		i++;
	}
	newvar = ft_strnew(ft_strlen(var) + ft_strlen(val) + 2);
	ft_strcat(newvar, var);
	ft_strcat(newvar, "=");
	ft_strcat(newvar, val);
	newenv[i++] = newvar;
	newenv[i] = NULL;
	return (newenv);
}

char			**set_envar(char *var, char *val, char **env)
{
	if (ft_strchr(var, '='))
		ft_putendl("invalid char in variable name: =");
	else if (val == NULL)
		env = delete_envar(var, env);
	else if (get_envar(var, env))
		env = update_envar(var, val, env);
	else
		env = create_envar(var, val, env);
	return (env);
}
