/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:46 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/19 16:22:51 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_path(char *path)
{
	if (!access(path, F_OK))
		return (1);
	free(path);
	return (0);
}

char	*get_cmd_path(char *cmd)
{
	char	*add_slash;
	char	*path;
	int		i;

	path = NULL;
	add_slash = NULL;
	if (ft_strchr(cmd, '/') && !access(cmd, F_OK))
		return (ft_strdup(cmd));
	else if (ft_strchr(cmd, '/') && access(cmd, F_OK))
		return (NULL);
	i = -1;
	(data()->env_path) = ft_split(my_getenv("PATH"), ':');
	while (data()->env_path && data()->env_path[++i])
	{
		add_slash = ft_strjoin(data()->env_path[i], "/");
		path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (is_path(path))
			break ;
		else
			path = NULL;
	}
	return (get_path(cmd, path));
}

int	new_pipe(int *i, int j, t_cmd **end)
{
	if (ft_equals(data()->token[j], "|"))
	{
		*i = 0;
		data()->npipes++;
		if (!data()->cmd)
			return (1);
		(*end)->next = ft_calloc(1, sizeof(t_cmd));
		(*end)->fd_out = 1;
		*end = (*end)->next;
		return (1);
	}
	return (0);
}

void	save_exec_args(void)
{
	t_cmd	*cmd;
	int		i;
	int		j;

	cmd = data()->cmd;
	while (cmd)
	{
		i = 0;
		j = 0;
		while (cmd->args[i] && !ft_equals(cmd->args[i], "<")
			&& !ft_equals(cmd->args[i], "<<")
			&& !ft_equals(cmd->args[i], ">")
			&& !ft_equals(cmd->args[i], ">>"))
		{
			if (i == 0)
				cmd->path = get_cmd_path(cmd->args[i]);
			cmd->exec_args[j++] = cmd->args[i++];
		}
		if (cmd->args[i])
			cmd->redir = 1;
		cmd = cmd->next;
	}
}

int	create_commands(void)
{
	int		i;
	int		j;
	t_cmd	*end;

	j = -1;
	i = 0;
	data()->cmd = NULL;
	while (data()->token[++j])
	{
		if (new_pipe(&i, j, &end))
			continue ;
		if (!data()->cmd)
		{
			(data()->cmd) = ft_calloc(1, sizeof(t_cmd));
			data()->cmd->fd_out = 1;
			end = data()->cmd;
		}
		end->args[i++] = expand_env(data()->token[j]);
	}
	data()->error = NONE;
	save_exec_args();
	free_tokens();
	return (0);
}
