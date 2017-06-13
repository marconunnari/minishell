/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:11:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/13 22:07:37 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**minishell(char *cmd, char **env)
{
	char	*prog;
	char	**argv;

	if (parsecmd(cmd, &prog, &argv, env))
		env = run_prog(prog, argv, env);
	return (env);
}

int		main(int argc, char **argv, char **env)
{
	char	*cmd;

	(void)argc;(void)argv;(void)env;
	ft_printf("minishell> ");
	while (get_next_line(0, &cmd) > 0)
	{
		env = minishell(cmd, env);
		ft_printf("minishell> ");
	}
	ft_printfnl("exit");
}
