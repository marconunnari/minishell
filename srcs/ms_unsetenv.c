/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:48:22 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/13 17:03:40 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**ms_unsetenv(int argc, char **argv, char **env)
{
	if (argc == 1)
		ft_putendl("unsetenv: too few arguments");
	else
		while (*argv)
			env = set_envar(*argv++, NULL, env);
	return (env);
}
