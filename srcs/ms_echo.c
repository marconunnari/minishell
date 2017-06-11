/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:45:37 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/10 18:46:58 by mnunnari         ###   ########.fr       */
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

void			print_var(char *var, char **env)
{
	int		varlen;

	varlen = ft_strlen(var);
	while (*env)
	{
		if (ft_strnequ(var, *env, varlen))
			ft_printf("%s", &((*env)[varlen + 1]));
		env++;
	}
}

void			print_args(char **argv, int i, char **env)
{
	while (argv[i])
	{
		if (argv[i][0] == '$')
			print_var(&(argv[i][1]), env);
		else
			ft_putstr(argv[i]);
		i++;
		if (argv[i])
			ft_putchar(' ');
	}
}

int				ms_echo(int argc, char **argv, char ***env)
{
	int		newline;
	int		i;

	(void)argc;
	i = 1;
	newline = is_newline(argv, &i);
	print_args(argv, i, *env);
	if (newline)
		ft_putchar('\n');
	return (0);
}
