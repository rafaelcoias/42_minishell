/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:36:01 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/11 11:18:32 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*	This function sees what command or
 *	commands did the user write, pipe by
 *	pipe until "n_of_pipes" is reached.
 *
 *	Split functions is used to divide the
 *	command by spaces to see the first word
 *	written.
 *
 * If there is an invalid command, it returns
 *	an error.
 * */

void	read_command(t_data *data)
{
	int	i;

	i = 0;
	while (data->pipes[i])
	{
		data->cmd = ft_split(data->pipes[i++], ' '); 
		if (!ft_strcmp(data->cmd[0], PWD_CMD))	
			pwd_command();
		else if (!ft_strcmp(data->cmd[0], ECHO_CMD))
			echo_command(data);
		else if (!ft_strcmp(data->cmd[0], EXIT_CMD))
			data->exit = 1;
		else
			error_msg(CMD_ERROR);
		ft_free_mtx(data->cmd);
	}
}
