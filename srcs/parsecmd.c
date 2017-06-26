/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:30:56 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/13 22:07:28 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			freetok(void *c, size_t s)
{
	(void)s;
	free(c);
}

int				parsecmd(char *cmd, char **prog, char ***argv, char **env)
{
	char	*tok;
	t_list	*toks;
	t_list	*tokscpy;
	int		n;

	(void)prog; (void)argv;
	toks = NULL;
	while ((n = get_next_tok(&cmd, &tok, env)) > 0)
		ft_lstpushnew(&toks, tok, ft_strlen(tok) + 1);
	if (n == -1 || toks == NULL)
		return (0);
	*prog = ft_strdup((char*)toks->content);
	*argv = (char**)malloc(sizeof(char*) * (ft_lstlen(toks) + 1));
	tokscpy = toks;
	n = 0;
	while (toks)
	{
		(*argv)[n++] = ft_strdup((char*)toks->content);
		ft_printfnl("tok %s", (*argv)[n - 1]);
		toks = toks->next;
	}
	(*argv)[n] = NULL;
	ft_lstdel(&tokscpy, freetok);
	return (1);
}
