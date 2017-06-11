/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 05:47:14 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 08:56:54 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*get_path(int argc, char **argv, char **env, char *prev)
{
	if (argc > 2)
	{
		ft_putendl("cd: too many arguments");
		return (NULL);
	}
	if (argc == 1 || ft_strequ(argv[1], "~"))
		return (get_envar("HOME", env));
	if (ft_strequ(argv[1], "-"))
	{
		if (prev == NULL)
			ft_putendl("cd: no previous directory");
		else
			ft_putendl(prev);
		return (prev);
	}
	return (argv[1]);
}

static int		path_err(char *msg, char *path)
{
	ft_printfnl("cd: %s: %s", msg, path);
	return (0);
}

int				check_dir(char *path)
{
	int				res;
	struct stat		info;

	res = access(path, F_OK);
	if (res != 0)
		return (path_err("no such file or directory", path));
	res = access(path, X_OK);
	if (res != 0)
		return (path_err("permission denied", path));
	if (stat(path, &info) == -1)
		return (path_err("error in retrieving info", path));
	if (!S_ISDIR(info.st_mode))
		return (path_err("not a directory", path));
	return (1);
}

char			**ms_cd(int argc, char **argv, char **env)
{
	char		*path;
	static char	*prev;

	path = get_path(argc, argv, env, prev);
	prev = getcwd(prev, MAXPATHLEN);
	if (path == NULL)
		return (env);
	if (check_dir(path))
	{
		chdir(path);
		env = set_envar("PWD", getcwd(path, MAXPATHLEN), env);
		env = set_envar("OLDPWD", prev, env);
	}
	return (env);
}
