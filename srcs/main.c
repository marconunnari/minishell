#include "minishell.h"

void	exec_cmd(char *cmd)
{
	pid_t	child_pid;
	int	stat_loc;

	if ((child_pid = fork()) < 0)
		ft_error("fork error", 1);
	else if (child_pid == 0)
	{
		ft_printfnl("exec %s", cmd);
		exit(1);
	}
	else
	{
		//todo: background
		waitpid(child_pid, &stat_loc, WUNTRACED);
		ft_printf("$> ");
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*cmd;

	(void)argc;(void)argv;(void)env;
	ft_printf("$> ");
	while (get_next_line(0, &cmd) > 0)
		exec_cmd(cmd);
}
