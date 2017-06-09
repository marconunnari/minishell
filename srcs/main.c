/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:11:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/09 15:56:05 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char *cmd, char **env)
{
	char	*prog;
	char	**argv;

	if (parsecmd(cmd, &prog, &argv))
		run_prog(prog, argv, env);
}

int		main(int argc, char **argv, char **env)
{
	char	*cmd;

	(void)argc;(void)argv;(void)env;
	ft_printf("minishell> ");
	while (get_next_line(0, &cmd) > 0)
	{
		minishell(cmd, env);
		ft_printf("minishell> ");
	}
	ft_printfnl("exit");
}
