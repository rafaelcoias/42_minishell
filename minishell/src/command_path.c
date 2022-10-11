/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:46 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/10 14:28:37 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char*	get_cmd_path(t_data *data)
{
	char	*add_slash;
	char	*path;
	int		i;

	if (ft_strchr(data->cmd[0], '/') && !access(data->cmd[0], F_OK))
		return (data->cmd[0]);
	else if (ft_strchr(data->cmd[0], '/') && access(data->cmd[0], F_OK))
	{
		error_msg(CMD_ERROR);
		return (NULL);
	}
	i = -1;
	while (data->envp[++i])
	{
		add_slash = ft_strjoin(data->envp[i], "/");
		path = ft_strjoin(add_slash, data->cmd[0]);
		free(add_slash);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	error_msg(CMD_ERROR);
	return (NULL);
}
