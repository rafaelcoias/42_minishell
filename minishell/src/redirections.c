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

int	heredoc(t_cmd *cmd, int i)
{
	char	*limiter;
	char	*line;

	(data()->fd_heredoc) = open(".here_doc", O_CREAT | O_WRONLY \
	| O_TRUNC, 0644);
	if (data()->fd_heredoc == -1)
		error_msg(OPEN_ERROR);
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
	return (1);
}

void	redirect_input(t_cmd *cmd, int i)
{
	if (i != 0)
	{
		cmd->fd_in = open(cmd->args[i - 1], O_RDONLY);
		dup2(cmd->fd_in, STDIN_FILENO);
	}
}

void	redirect_output(t_cmd *cmd, int i)
{
	if (ft_equals(cmd->args[i], ">>") && cmd->args[i + 1])
		cmd->fd_out = open(cmd->args[i + 1], O_CREAT \
		| O_WRONLY | O_APPEND, 0644);
	else if (ft_equals(cmd->args[i], ">") && cmd->args[i + 1])
		cmd->fd_out = open(cmd->args[i + 1], O_CREAT \
		| O_WRONLY | O_TRUNC, 0644);
	dup2(cmd->fd_out, STDOUT_FILENO);
}

void	redirections(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		if (ft_equals(cmd->args[i], "<<"))
			heredoc(cmd, i);
		else if (ft_equals(cmd->args[i], "<"))
			redirect_input(cmd, i);
		else if (ft_equals(cmd->args[i], ">>")
			|| ft_equals(cmd->args[i], ">"))
			redirect_output(cmd, i);
		i++;
	}
}
