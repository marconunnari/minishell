/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:45:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/09 16:48:41 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ms_echo(int argc, char **argv, char **env)
{
	int		newline;

	(void)argc;(void)argv;(void)env;
	argv++;
	newline = 1;
	if (ft_strequ(*argv, "-n"))
	{
		newline = 0;
		argv++;
	}
	while(*argv)
	{
		ft_printf("%s", *argv++);
		if (*argv)
			ft_putchar(' ');
	}
	if (newline)
		ft_putchar('\n');
	return (0);
}
