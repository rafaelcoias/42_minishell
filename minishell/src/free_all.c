/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:26:20 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/11 19:26:20 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void free_tokens()
{
    int i;

    i = 0;
    while (data()->token[i])
        free(data()->token[i++]);
}

static void free_cmds()
{
    t_cmd	*aux;
	t_cmd	*temp;

	aux = data()->cmd;
	while (aux)
	{
		temp = data()->cmd->next;
		free(aux->path);
		free(aux);
		aux = temp;
	}
}

/*	Free everything in data list
	And frees input
 */

void	free_all(char *input)
{
	free_cmds();
    free_tokens();
	free(input);
}