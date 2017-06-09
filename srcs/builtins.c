/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:48:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/09 16:45:58 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void			check_opts(char *prog, char *opts, char *valids)
{
	int	i;

	i = 0;
	while (opts[i])
	{
		if (!ft_strcont(valids, opts[i]))
		{
			ft_dprintf(2, "%s: illegal option -- %c\n", prog,  opts[i]);
			ft_dprintf(2, "%s\n", "usage: %s [-%s] [file ...]");
			exit(1);
		}
		i++;
	}
}

int				parse_opts(int argc, char **argv, char **opts, char *valids)
{
	int			i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		if (ft_strequ(argv[i], "--"))
		{
			i++;
			break ;
		}
		args->opts = ft_strmerge(args->opts, ft_strdup(&argv[i][1]));
		i++;
	}
	check_opts(opts, valids);
	return (i);
}
*/
int				ms_cd(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing cd");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}

int				ms_setenv(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing setenv");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}

int				ms_unsetenv(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing unsetenv");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}

int				ms_env(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	ft_printf("executing env");
	while(*argv)
		ft_printf(" %s", *argv++);
	ft_printfnl("...");
	return (0);
}
