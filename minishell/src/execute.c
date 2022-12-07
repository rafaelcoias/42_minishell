/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:44 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/12 00:09:30 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	close_fds(int in, int out)
{
	if (in != 0)
		close(in);
	if (out != 1)
		close(out);
}

void	wait_childs(void)
{
	t_cmd	*tmp;

	tmp = data()->cmd;
	while (tmp)
	{
		waitpid(tmp->pid, 0, 0);
		tmp = tmp->next;
	}
}

void	exec(t_cmd *cmd, int in, int out)
{
	if (!ft_strcmp(cmd->args[0], CD_CMD))
		return (cd_command(cmd->args));
	cmd->pid = fork();
	if (!cmd->pid)
	{
		close(cmd->pipe[0]);
		if (out != STDOUT_FILENO)
			dup2(out, STDOUT_FILENO);
		if (in != STDIN_FILENO)
			dup2(in, STDIN_FILENO);
		close_fds(in, out);
		redirections(cmd);
		check_builtins(cmd);
		if (execve(cmd->path, cmd->exec_args, data()->envp) == -1)
			error_msg(EXEC_ERROR);
		exit(0);
	}
	close_fds(in, out);
}

int	execute(void)
{
	t_cmd	*tmp;
	int		fd_in;
	int		index;

	index = 0;
	fd_in = STDIN_FILENO;
	tmp = data()->cmd;
	while (tmp)
	{
		if (pipe(tmp->pipe) == -1)
			return (error_msg(PIPE_ERROR));
		if (index != data()->npipes)
			exec(tmp, fd_in, tmp->pipe[1]);
		else
			exec(tmp, fd_in, STDOUT_FILENO);
		fd_in = tmp->pipe[0];
		tmp = tmp->next;
		index++;
	}
	wait_childs();
	return (0);
}
