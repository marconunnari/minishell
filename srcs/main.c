/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:11:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/06 21:27:00 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char *cmd, char **env)
{
	pid_t	child_pid;

	if ((child_pid = fork()) < 0)
		ft_error("Fork error", 1);
	else if (child_pid == 0)
	{
		char *argv[2];
		argv[0] = "ls";
		argv[1] = NULL;
		execve("/bin/ls", argv, env);
		ft_printfnl("Error executing %s", cmd);
	}
	waitpid(child_pid, 0, 0);
}

int		main(int argc, char **argv, char **env)
{
	char	*cmd;

	(void)argc;(void)argv;(void)env;
	ft_printf("minishell> ");
	while (get_next_line(0, &cmd) > 0)
	{
		exec_cmd(cmd, env);
		ft_printf("minishell> ");
	}
	ft_printfnl("exit");
}
