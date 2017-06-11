#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <dirent.h>

typedef			int (*t_builtin)(int, char**, char***);

int				parsecmd(char *cmd, char **prog, char ***argv);
int				get_next_tok(char **str, char **arg);
void			run_prog(char *prog, char **argv, char **env);
void			ms_find_prog(char **prog, char **env);

t_builtin		get_builtin(char *prog);
int				ms_echo(int argc, char **argv, char ***env);
int				ms_cd(int argc, char **argv, char ***env);
int				ms_setenv(int argc, char **argv, char ***env);
int				ms_unsetenv(int argc, char **argv, char ***env);
int				ms_env(int argc, char **argv, char ***env);
int				ms_exit(int argc, char **argv, char ***env);
#endif
