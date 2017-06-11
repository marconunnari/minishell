/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:48:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/10 18:46:28 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ms_setenv(int argc, char **argv, char ***env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing setenv");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}

int				ms_unsetenv(int argc, char **argv, char ***env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing unsetenv");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}

int				ms_env(int argc, char **argv, char ***env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing env");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}

int				ms_cd(int argc, char **argv, char ***env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing cd");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}
