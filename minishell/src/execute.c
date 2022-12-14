/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:44 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 15:03:57 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	close_fds(int in, int out, int dup)
{
	if (dup && in != STDIN_FILENO)
		dup2(in, STDIN_FILENO);
	if (dup && out != STDOUT_FILENO)
		dup2(out, STDOUT_FILENO);
	if (in != 0)
		close(in);
	if (out != 1)
		close(out);
}

void	wait_childs(void)
{
	t_cmd	*tmp;
	int		status;

	tmp = data()->cmd;
	while (tmp)
	{
		waitpid(tmp->pid, &status, 0);
		tmp = tmp->next;
	}
}

void	exec(t_cmd *cmd, int in, int out)
{
	if (check_builtins(cmd))
		return ;
	if (!cmd->path)
		return ((void)error_msg(EXEC_ERROR));
	cmd->pid = fork();
	if (!cmd->pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		close(cmd->pipe[0]);
		close_fds(in, out, 1);
		if (redirections(cmd))
			return ;
		forked_builtins(cmd);
		if (execve(cmd->path, cmd->exec_args, data()->env) == -1)
			error_msg(EXEC_ERROR);
		exit(ft_atoi(data()->error));
	}
	signal_handler_block();
	close_fds(in, out, 0);
}

int	check_question_mark(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		if (ft_strchr(args[i], '?'))
			return (error_msg(NO_MATCHES_ERROR));
	return (0);
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
		data()->error = NONE;
		if (pipe(tmp->pipe) == -1)
			return (error_msg(PIPE_ERROR));
		if (!check_question_mark(tmp->args))
		{
			if (index != data()->npipes)
				exec(tmp, fd_in, tmp->pipe[1]);
			else
				exec(tmp, fd_in, STDOUT_FILENO);
		}
		fd_in = tmp->pipe[0];
		tmp = tmp->next;
		index++;
	}
	wait_childs();
	return (0);
}
