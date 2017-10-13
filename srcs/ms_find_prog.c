/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:30:39 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/09 15:34:06 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		prepend_path(char *dir, char **prog)
{
	char	*old;

	old = *prog;
	*prog = ft_strjoin(dir, "/");
	*prog = ft_strmerge(*prog, old);
}

static int		prog_in_dir(char *dir, char *prog)
{
	DIR				*dirp;
	struct dirent	*entry;

	dirp = opendir(dir);
	if (dirp == NULL)
		return (0);
	while ((entry = readdir(dirp)))
		if (ft_strequ(entry->d_name, prog))
			return (1);
	closedir(dirp);
	return (0);
}

static int		process_path(char *path, char **prog)
{
	char	**dirs;
	int		i;
	int		found;

	path += 5;
	dirs = ft_strsplit(path, ':');
	i = 0;
	found = 0;
	while (dirs[i])
	{
		if (prog_in_dir(dirs[i], *prog))
		{
			prepend_path(dirs[i], prog);
			found = 1;
			break;
		}
		i++;
	}
	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
	return (found);
}

void			ms_find_prog(char **prog, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], "PATH", 4))
		{
			if (process_path(env[i], prog))
				return ;
		}
		i++;
	}
	ft_printfnl("%s: Program not found", *prog);
	*prog = NULL;
}
