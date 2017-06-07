#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <sys/wait.h>

int			parsecmd(char *cmd, char **prog, char ***argv);
#endif
