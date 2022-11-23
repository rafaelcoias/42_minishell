/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:46 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 18:05:17 by gseco-lu         ###   ########.fr       */
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

char	*get_cmd_path(char *cmd)
{
	char	*add_slash;
	char	*path;
	int		i;

	if (ft_strchr(cmd, '/') && !access(cmd, F_OK))
		return (cmd);
	else if (ft_strchr(cmd, '/') && access(cmd, F_OK))
		return (NULL);
	i = -1;
	while (data()->env_path[++i])
	{
		add_slash = ft_strjoin(data()->env_path[i], "/");
		path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	return (NULL);
}

/*	Creates a command based on the tokens */
t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	return (cmd);
}

int	equas(const char *a, const char *b)
{
	if (a == NULL || b == NULL)
		return (0);
	while (*a && b && *a == *b )
	{
		a++;
		b++;
	}
	return (*a == *b);
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
		if (equas(data()->token[j], "|"))
		{
			i = 0;
			if (!data()->cmd)
				continue ;
			end->next = new_cmd();
			end = end->next;
			continue ;
		}
		if (!data()->cmd)
		{	
			data()->cmd = new_cmd();
			end = data()->cmd;
		}
		if (i == 0)
			end->path = get_cmd_path(data()->token[j]);
		end->args[i++] = data()->token[j];
	}
	return (0);
}
