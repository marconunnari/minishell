#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/param.h>
# include <sys/stat.h>

typedef			char**(*t_builtin)(int, char**, char**);

int				parsecmd(char *cmd, char **prog, char ***argv);
int				get_next_tok(char **str, char **arg);
char			**run_prog(char *prog, char **argv, char **env);
void			ms_find_prog(char **prog, char **env);

t_builtin		get_builtin(char *prog);
char			**ms_echo(int argc, char **argv, char **env);
char			**ms_cd(int argc, char **argv, char **env);
char			**ms_setenv(int argc, char **argv, char **env);
char			**ms_unsetenv(int argc, char **argv, char **env);
char			**ms_env(int argc, char **argv, char **env);
char			**ms_exit(int argc, char **argv, char **env);

char			*get_envar(char *var, char **env);
void			print_env(char **env);
char			**set_envar(char *var, char *val, char **env);
#endif
