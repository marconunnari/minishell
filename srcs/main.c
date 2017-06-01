#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*cmd;
	pid_t	child_pid;
	int	stat_loc;

	(void)argc;(void)argv;(void)env;
	ft_printf("$> ");
	while (get_next_line(0, &cmd) > 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			ft_printfnl("%s executed", cmd);
			break;
		}
		else if (child_pid > 0)
		{
			waitpid(child_pid, &stat_loc, WUNTRACED);
			ft_printf("$> ");
		}
		else
			ft_error("fork error", 1);
	}
}
