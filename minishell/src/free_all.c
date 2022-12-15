/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:26:20 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/15 19:46:56 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_tokens(void)
{
	int	i;

	i = 0;
	while (data()->token[i])
		free(data()->token[i++]);
}

void	free_cmds(void)
{
	t_cmd	*aux;
	t_cmd	*temp;
	int		i;

	aux = data()->cmd;
	while (aux)
	{
		temp = aux->next;
		if (aux->path)
			free(aux->path);
		i = 0;
		while (aux->args[i])
			free(aux->args[i++]);
		free(aux);
		aux = temp;
	}
}

/*	Free everything in data list
	Frees input
	Removes .here_doc file if exists
 */

void	free_all(char *input)
{
	if (data()->token)
		free_tokens();
	if (data()->cmd)
		free_cmds();
	unlink(".here_doc");
	if (input)
		free(input);
	free(data()->prompt);
}
