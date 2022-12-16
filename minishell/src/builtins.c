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

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, PWD_CMD))
		return (1);
	else if (!ft_strcmp(cmd, ECHO_CMD))
		return (1);
	else if (!ft_strcmp(cmd, CD_CMD))
		return (1);
	else if (!ft_strcmp(cmd, EXPORT_CMD))
		return (1);
	else if (!ft_strcmp(cmd, UNSET_CMD))
		return (1);
	else if (!ft_strcmp(cmd, ENV_CMD))
		return (1);
	return (0);
}

int	forked_builtins(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->exec_args[0], PWD_CMD))
		pwd_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], ECHO_CMD))
		echo_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], CD_CMD))
		cd_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], EXIT_CMD))
		exit_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], UNSET_CMD))
		unset_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], EXPORT_CMD))
		export_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], ENV_CMD))
		env_command(cmd->exec_args);
	else
		return (0);
	ft_free_mtx(data()->env);
	exit(ft_atoi(data()->error));
}

/*	This function sees what command or
 *	commands did the user write.
 *
 *	Split functions is used to divide the
 *	command by spaces to see the first word
 *	written.
 * */

int	check_builtins(t_cmd *cmd)
{
	if (data()->npipes)
		return (0);
	if (!ft_strcmp(cmd->exec_args[0], CD_CMD))
		cd_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], EXIT_CMD))
		exit_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], UNSET_CMD))
		unset_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], EXPORT_CMD)
		&& ft_mtxlen(cmd->exec_args) != 1)
		export_command(cmd->exec_args);
	else if (!ft_strcmp(cmd->exec_args[0], ENV_CMD) && !cmd->redir
		&& ft_mtxlen(cmd->exec_args) != 1)
		env_command(cmd->exec_args);
	else
		return (0);
	return (1);
}
