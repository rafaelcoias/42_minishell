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

/*
	Execute is the function that executes any
	command.

  First it closes the read/input side of the pipe
  and then it changes the fd of the write/output
  side of the pipe.

  If there is an output redirection ">" or ">>"
  dup2() is used on the outfile fd.

  Finally, it executes the command by getting its
  path with the get_cmd_path() function.
*/

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

/*	This function runs every command until
 *	there are no commands (pipes) left.
 *
 *	If there is an input redirection "<", then
 *	the fd of the file pointed to by "<" is changed
 *	to be the input of the first command.
 *
 *	After that, a pipe is created using the pipe
 *	function. The command line equivalent to
 *	that pipe is executed in the exec() function.
 *
 *	close() function are used to always close
 *	the fd of the write/output side of the pipe.
 *
 *	dup2() function is used to change the fd
 *	of the read/input side of the pipe.
 * */
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
		if (index++ == 0)
		{
			tmp->fd[0] = STDIN_FILENO;
			tmp->fd[1] = STDOUT_FILENO;
		}
		else if (pipe(tmp->fd) == -1)
			return (error_msg(PIPE_ERROR));
		exec(tmp, fd_in, tmp->fd[1]);
		fd_in = tmp->fd[0];
		tmp = tmp->next;
	}
	wait_childs();
	return (0);
}
