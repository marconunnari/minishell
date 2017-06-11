/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:45:55 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 09:33:10 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**ms_setenv(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	if (argc == 1)
		print_env(env);
	else if (argc == 2)
		env = set_envar(argv[1], "", env);
	else if (argc == 3)
		env = set_envar(argv[1], argv[2], env);
	else
		ft_putendl("setenv: too many arguments");
	return (env);
}
