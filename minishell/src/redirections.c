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

int	check_file(char *file, int in)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		return (error_msg(FILE_IS_DIR_ERROR));
	if (in && access(file, F_OK))
		return (error_msg(FILE_ERROR));
	close(fd);
	return (0);
}

int	heredoc(t_cmd *cmd, int i)
{
	char	*limiter;
	char	*line;

	(data()->fd_heredoc) = open(".here_doc", O_CREAT | O_WRONLY \
	| O_TRUNC, 0644);
	if (data()->fd_heredoc == -1)
		return (error_msg(OPEN_ERROR));
	limiter = ft_strjoin(cmd->args[i + 1], "\n");
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(0);
		if (ft_equals(line, limiter))
			break ;
		write(data()->fd_heredoc, line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(limiter);
	close(data()->fd_heredoc);
	cmd->fd_in = open(".here_doc", O_RDONLY);
	dup2(cmd->fd_in, STDIN_FILENO);
	return (0);
}

int	redirect_input(t_cmd *cmd, int i)
{
	if (i != ft_mtxlen(cmd->args) - 1)
	{
		if (check_file(cmd->args[i + 1], 1))
			return (1);
		cmd->fd_in = open(cmd->args[i + 1], O_RDONLY);
		if (cmd->fd_in == -1)
			return (error_msg(OPEN_ERROR));
		dup2(cmd->fd_in, STDIN_FILENO);
	}
	return (0);
}

int	redirect_output(t_cmd *cmd, int i)
{
	if (check_file(cmd->args[i + 1], 0))
		return (1);
	if (ft_equals(cmd->args[i], ">>") && cmd->args[i + 1])
		cmd->fd_out = open(cmd->args[i + 1], O_CREAT \
		| O_WRONLY | O_APPEND, 0644);
	else if (ft_equals(cmd->args[i], ">") && cmd->args[i + 1])
		cmd->fd_out = open(cmd->args[i + 1], O_CREAT \
		| O_WRONLY | O_TRUNC, 0644);
	if (cmd->fd_out == -1)
			return (error_msg(OPEN_ERROR));
	dup2(cmd->fd_out, STDOUT_FILENO);
	return (0);
}

int	redirections(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		if (ft_equals(cmd->args[i], "<<"))
		{
			if (heredoc(cmd, i))
				return (1);
		}
		else if (ft_equals(cmd->args[i], "<"))
		{
			if (redirect_input(cmd, i))
				return (1);
		}
		else if (ft_equals(cmd->args[i], ">>")
			|| ft_equals(cmd->args[i], ">"))
		{
			if (redirect_output(cmd, i))
				return (1);
		}
		i++;
	}
	return (0);
}
