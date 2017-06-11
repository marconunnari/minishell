/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:48:53 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 08:29:02 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**ms_env(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	if (argc == 1)
		print_env(env);
	return (env);
}
