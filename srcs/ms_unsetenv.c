/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:48:22 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 08:28:44 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**ms_unsetenv(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing unsetenv");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (env);
}
