/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:45:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/11 08:30:40 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				is_newline(char **argv, int *i)
{
	if (argv[*i] && ft_strequ(argv[*i], "-n"))
	{
		*i = *i + 1;
		return (0);
	}
	return (1);
}

void			print_args(char **argv, int i, char **env)
{
	(void)env;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		i++;
		if (argv[i])
			ft_putchar(' ');
	}
}

char			**ms_echo(int argc, char **argv, char **env)
{
	int		newline;
	int		i;

	(void)argc;
	i = 1;
	newline = is_newline(argv, &i);
	print_args(argv, i, env);
	if (newline)
		ft_putchar('\n');
	return (env);
}
