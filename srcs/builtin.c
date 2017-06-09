/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:40:13 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/09 13:40:15 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		add_builtin(char *key, t_builtin val, t_list **lst)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->key = key;
	map->value = val;
	ft_lstaddnew(lst, map, sizeof(t_map));
	free(map);
}

t_builtin		get_builtin(char *prog)
{
	t_list	*lst;

	lst = NULL;
	add_builtin("echo", ms_echo, &lst);
	add_builtin("cd", ms_cd, &lst);
	add_builtin("setenv", ms_setenv, &lst);
	add_builtin("unsetenv", ms_unsetenv, &lst);
	add_builtin("env", ms_env, &lst);
	add_builtin("exit", ms_exit, &lst);
	return (ft_mapget_lst(lst, prog, (int (*)(void *, void *))ft_strequ));
}

int				ms_exit(int argc, char **argv, char **env)
{
	(void)argc;(void)argv;(void)env;
	if (argc == 1)
		exit(0);
	else
		ft_printfnl("usage: exit");
	return (0);
}
