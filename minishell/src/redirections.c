/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:36:01 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 15:03:37 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	return (0);
}

int	redirect_input(t_cmd *cmd, int i)
{
	int	fd;

	if (i != ft_mtxlen(cmd->args) - 1)
	{
		fd = open(cmd->args[i + 1], O_DIRECTORY);
		if (fd > 0)
		{
			close(fd);
			return (error_msg(FILE_IS_DIR_ERROR));
		}
		if (access(cmd->args[i + 1], F_OK))
			return (error_msg(FILE_ERROR));
		cmd->fd_in = open(cmd->args[i + 1], O_RDONLY);
		if (cmd->fd_in == -1)
			return (error_msg(OPEN_ERROR));
	}
	return (0);
}

int	redirect_output(t_cmd *cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i + 1], O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (error_msg(FILE_IS_DIR_ERROR));
	}
	if (ft_equals(cmd->args[i], ">>") && cmd->args[i + 1])
		cmd->fd_out = open(cmd->args[i + 1], O_CREAT \
		| O_WRONLY | O_APPEND, 0644);
	else if (ft_equals(cmd->args[i], ">") && cmd->args[i + 1])
		cmd->fd_out = open(cmd->args[i + 1], O_CREAT \
		| O_WRONLY | O_TRUNC, 0644);
	if (cmd->fd_out == -1)
		return (error_msg(OPEN_ERROR));
	return (0);
}

int	create_files(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		if (ft_equals(cmd->args[i], "<"))
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

int	redirections(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		if (ft_equals(cmd->args[i], "<<")
			|| ft_equals(cmd->args[i], "<"))
		{
			if (ft_equals(cmd->args[i], "<<") && heredoc(cmd, i))
				return (1);
			else if (ft_equals(cmd->args[i], "<") && redirect_input(cmd, i))
				return (1);
			dup2(cmd->fd_in, STDIN_FILENO);
		}
		else if (ft_equals(cmd->args[i], ">>")
			|| ft_equals(cmd->args[i], ">"))
		{
			if (redirect_output(cmd, i))
				return (1);
			dup2(cmd->fd_out, STDOUT_FILENO);
		}
		i++;
	}
	return (0);
}
