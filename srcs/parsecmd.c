/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:30:56 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/07 20:32:56 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		quoted(char **str, t_list **args)
{
	char	*c;

	c = *str++;


}

static void		parse_args(char ***argv, char *prog, char *str)
{
	t_list	*args;
	char	*close;
	char	*arg;

	args = NULL;
	while (*str)
	{
		if (*str == '\"' || *str == '\'')
			quoted(&str, &args);
		else if (*str == ' ')
			spaces(&str, &args);
		str++;
	}
	*argv = ft_lstoarr(args);
	ft_lstdel(args);
}

int				parsecmd(char *cmd, char **prog, char ***argv)
{
	char	*argstr;

	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	if (!cmd)
		return (0);
	argstr = ft_strchr(cmd, ' ');
	if (argstr)
	{
		*prog = ft_strsub(cmd, 0, argstr - cmd);
//		parse_args(argv, *prog, argstr);
	}
	else
	{
		*prog = ft_strdup(cmd);
		*argv = (char**)malloc(sizeof(char*) * 2);
		(*argv)[0] = *prog;
		(*argv)[1] = NULL;
	}
	return (1);
}
