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

static int redirect_input(t_data *data)
{
	(void)data;
	return (0);
}

static int redirect_output(t_data *data)
{
	(void)data;
	return (0);
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

static int	execute(t_data *data, int i)
{
	close(data->pipe_fd[0]);
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	if (redirect_output(data))
		dup2(data->outfile_fd, STDOUT_FILENO);
	if (execve(get_cmd_path(data), &data->pipes[i], data->envp) == -1)
		return (error_msg(EXEC_ERROR));
	return (0);
}

/*	This function runs every command until
 *	there are no pipes left.
 *
 *	If there is an input redirection "<", then
 *	the fd of the file pointed to by "<" is changed
 *	to be the input of the first command.
 *
 *	After that, a pipe is created using the pipe
 *	function. The command line equivalent to
 *	that pipe is executed in the execute() function.
 *
 *	close() function are used to always close 
 *	the fd of the write/output side of the pipe.
 *
 *	dup2() function is used to change the fd
 *	of the read/input side of the pipe.
 * */

int	handle_pipe(t_data *data)
{
	int	pid_child;
	int	i;

	i = 0;
	if (redirect_input(data))
		dup2(data->infile_fd, STDIN_FILENO);
	while (data->pipes[i])
	{
		if (pipe(data->pipe_fd) == -1)
			return (error_msg(PIPE_ERROR));
		pid_child = fork();
		if (pid_child == -1)
			error_msg(FORK_ERROR);
		if (!pid_child)
			return (execute(data, i));
		close(data->pipe_fd[1]);
		waitpid(pid_child, 0, 0);
		dup2(data->pipe_fd[0], STDIN_FILENO);
	}
	return (0);
}
