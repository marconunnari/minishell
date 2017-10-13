/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:24:57 by mnunnari          #+#    #+#             */
/*   Updated: 2017/10/13 17:06:46 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ms_error(char *prog, char *msg)
{
	ft_printfnl("%s: %s", prog, msg);
	exit(0);
}

static void		check_prog(char *prog)
{
	int				r;
	struct stat		s_stat;

	r = access(prog, F_OK);
	if (r != 0)
		ms_error(prog, "Program not found");
	r = access(prog, X_OK);
	if (r != 0)
		ms_error(prog, "Permission denied");
	stat(prog, &s_stat);
	if ((s_stat.st_mode & S_IFMT) == S_IFDIR)
		ms_error(prog, "Is a directory");
}

static void		exec_prog(char *prog, char **argv, char **env)
{
	if (!ft_strcont(prog, '/'))
		ms_find_prog(&prog, env);
	if (prog)
	{
		check_prog(prog);
		execve(prog, argv, env);
	}
	exit(1);
}

static void		run_extern(char *prog, char **argv, char **env)
{
	pid_t	child_pid;

	if ((child_pid = fork()) < 0)
		ft_error("Fork error", 1);
	if (child_pid == 0)
		exec_prog(prog, argv, env);
	waitpid(child_pid, 0, 0);
}

char			**run_prog(char *prog, char **argv, char **env)
{
	t_builtin	builtin;

	builtin = get_builtin(prog);
	if (builtin)
		env = builtin(ft_arrlen((void**)argv), argv, env);
	else
		run_extern(prog, argv, env);
	return (env);
}
