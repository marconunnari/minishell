/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:11:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/08 18:56:10 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void	exec_cmd(char *cmd, char **env)
{
	pid_t	child_pid;

	if ((child_pid = fork()) < 0)
		ft_error("Fork error", 1);
	else if (child_pid == 0)
		execve("/bin/ls", argv, env);
	waitpid(child_pid, 0, 0);
}
*/

void	minishell(char *cmd, char **env)
{
	char	*prog;
	char	**argv;

	(void)env;
	if (parsecmd(cmd, &prog, &argv))
	{
/*		ft_printf("prog: %s\n", prog);
		ft_putendl("argv:");
		while(*argv)
			ft_printfnl("%s", *argv++);
*/	}
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
