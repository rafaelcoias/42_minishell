/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:36:01 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/12 00:46:23 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*	This function sees what command or
 *	commands did the user write.
 *
 *	Split functions is used to divide the
 *	command by spaces to see the first word
 *	written.
 * */

void	check_builtins(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->args[0], PWD_CMD))
		pwd_command();
	else if (!ft_strcmp(cmd->args[0], ECHO_CMD))
		echo_command(cmd->args);
	else if (!ft_strcmp(cmd->args[0], EXIT_CMD))
		data()->exit = 1;
	else if (!ft_strcmp(cmd->args[0], CD_CMD))
		cd_command(cmd->args);
}

/*
	else if (!ft_strcmp(cmd->args[0], EXPORT_CMD))
		export_command();
	else if (!ft_strcmp(cmd->args[0], ENV_CMD))
		env_command();
	else if (!ft_strcmp(cmd->args[0], UNSET_CMD))
		unset_command();*/
