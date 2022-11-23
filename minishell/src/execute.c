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

/*
static int redirect_input()
{
	dup2(data()->fd_in, STDIN_FILENO);
	return (0);
}

static int redirect_output()
{
	dup2(data()->fd_out, STDOUT_FILENO);
	return (0);
}

static int heredoc()
{
	return (0);
}*/

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

static void	exec(t_cmd *cmd)
{
	close(data()->cmd->fd[0]);
	dup2(data()->cmd->fd[1], STDOUT_FILENO);
	check_builtins(cmd);
	if (execve(cmd->path, cmd->args, data()->envp) == -1)
		error_msg(EXEC_ERROR);
	exit(0);
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

	tmp = data()->cmd;
	while (tmp)
	{
		tmp->pid = fork();
		if (pipe(tmp->fd) == -1)
			return (error_msg(PIPE_ERROR));
		if (!tmp->pid)
			exec(tmp);
		close(tmp->fd[1]);
		dup2(tmp->fd[0], STDIN_FILENO);
		tmp = tmp->next;
	}
	wait_childs();
	return (0);
}
