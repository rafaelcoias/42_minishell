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

static void close_fds(int in, int out)
{
	if (in != 0)
		close(in);
	if (out != 1)
		close(out);
}

static void	wait_childs(void)
{
	t_cmd	*tmp;

	tmp = data()->cmd;
	while (tmp)
	{
		waitpid(tmp->pid, 0, 0);
		tmp = tmp->next;
	}
}

static void	exec(t_cmd *cmd, int in, int out)
{
	cmd->pid = fork();
	if (!cmd->pid)
	{
		dup2(out, STDOUT_FILENO);
		dup2(in, STDIN_FILENO);
		close_fds(in, out);
		check_builtins(cmd);
		if (execve(cmd->path, cmd->args, data()->envp) == -1)
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
		if (pipe(tmp->fd) == -1)
			return (error_msg(PIPE_ERROR));
		if (index++ == 0)
		{
			tmp->fd[0] = STDIN_FILENO;
			tmp->fd[1] = STDOUT_FILENO;
		}
		exec(tmp, fd_in, tmp->fd[1]);
		fd_in = tmp->fd[0];
		tmp = tmp->next;
	}
	wait_childs();
	return (0);
}

// static void close_fds(int in, int out)
// {
// 	if (in != 0)
// 		close(in);
// 	if (out != 1)
// 		close(out);
// }

// static void change_fds(int in, int out)
// {
// 	(void)in;
// 	// dup2(in, STDIN_FILENO);
// 	dup2(out, STDOUT_FILENO);
// }

// static void	wait_childs(void)
// {
// 	t_cmd	*tmp;

// 	tmp = data()->cmd;
// 	while (tmp)
// 	{
// 		waitpid(tmp->pid, 0, 0);
// 		tmp = tmp->next;
// 	}
// }

// static int	exec(t_cmd *cmd, int index)
// {
// 	cmd->pid = fork();
// 	if (cmd->pid == -1)
// 		return (error_msg(FORK_ERROR));
// 	if (!cmd->pid)
// 	{
// 		if (index == 0)
// 			change_fds(0, cmd->fd[1]);
// 		else if (index + 1 == data()->npipes)
// 			change_fds(cmd->fd[0], 1);
// 		else
// 			change_fds(cmd->fd[0], cmd->fd[1]);
// 		close_fds(cmd->fd[0], cmd->fd[1]);
// 		check_builtins(cmd);
// 		if (execve(cmd->path, cmd->args, data()->envp) == -1)
// 			error_msg(EXEC_ERROR);
// 		exit(0);
// 	}
// 	close_fds(cmd->fd[0], cmd->fd[1]);
// 	return (0);
// }

// int	execute(void)
// {
// 	int		index;
// 	t_cmd	*tmp;

// 	index = 0;
// 	tmp = data()->cmd;
// 	while (tmp)
// 	{
// 		if (data()->npipes && pipe(tmp->fd) == -1)
// 			return (error_msg(PIPE_ERROR));
// 		exec(tmp, index);
// 		index++;
// 		dup2(tmp->fd[1], STDIN_FILENO);
// 		tmp = tmp->next;
// 	}
// 	wait_childs();
// 	return (0);
// }
