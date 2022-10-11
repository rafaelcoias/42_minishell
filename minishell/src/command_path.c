/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:46 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/12 00:40:38 by rade-sar         ###   ########.fr       */
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
	while (data->env_path[++i])
	{
		add_slash = ft_strjoin(data->env_path[i], "/");
		path = ft_strjoin(add_slash, data->cmd[0]);
		free(add_slash);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	error_msg(CMD_ERROR);
	return (NULL);
}
