/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:44 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/19 16:24:00 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* This function searches for the command path.
 *
 * If first checks if there is a '/' and it tests
 * to see if the command already is its path.
 *
 * If the command has '/' but is no valid command
 * then it returns an error.
 *
 *	Then, the PATH variable in the ENVP list is read
 *	until the end. For every path it is added a '/'
 *	and then the command itself.
 *
 *	Finally, it tests the path and if it is accessable
 *	returns it, if not tries again with other path.
 *
 *	If there are no matches in the PATH variable,
 *	the command is invalid and return an error.
 * */

char	*get_path(char *cmd, char *path)
{
	if (data()->env_path)
		ft_free_mtx(data()->env_path);
	if (path && !access(path, F_OK))
		return (path);
	if (is_builtin(cmd))
		return (ft_strdup("path"));
	return (NULL);
}

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
	status = 0;
	while (tmp)
	{
		waitpid(tmp->pid, &status, 0);
		tmp = tmp->next;
	}
	if (status == 2 || status == 131)
		sig_handler_block(status);
	if (status == 256)
		data()->error = CAT_VALUE;
	else if (status == 512)
		data()->error = LS_VALUE;
}

void	exec(t_cmd *cmd, int in, int out)
{
	if (create_files(cmd))
		return ;
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
			exit(ft_atoi(data()->error));
		forked_builtins(cmd);
		if (execve(cmd->path, cmd->exec_args, data()->env) == -1)
			error_msg(EXEC_ERROR);
		exit(ft_atoi(data()->error));
	}
	signal(SIGINT, SIG_IGN);
	close_fds(in, out, 0);
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
		if (index != data()->npipes)
			exec(tmp, fd_in, tmp->pipe[1]);
		else
			exec(tmp, fd_in, STDOUT_FILENO);
		fd_in = tmp->pipe[0];
		tmp = tmp->next;
		index++;
	}
	wait_childs();
	return (free_cmds());
}
