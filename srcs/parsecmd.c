/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:30:56 by mnunnari          #+#    #+#             */
/*   Updated: 2017/06/08 19:00:27 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				parsecmd(char *cmd, char **prog, char ***argv)
{
	char	*tok;
	t_list	*toks;
	int		ret;

	(void)prog; (void)argv;
	toks = NULL;
	while ((ret = get_next_tok(&cmd, &tok)) > 0)
		ft_lstpushnew(&toks, tok, ft_strlen(tok) + 1);
	if (ret == -1 || toks == NULL)
		return (0);
	while (toks)
	{
		ft_printfnl("tok: %s", toks->content);
		toks = toks->next;
	}
	return (1);
}
