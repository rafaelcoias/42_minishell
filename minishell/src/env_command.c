/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:49 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 19:45:45 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int get_env_len(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}    

char	**cpy_env(char **env)
{
	char	**new_env;
    int		i;

    i = -1;
    new_env = malloc(sizeof(char *) * get_env_len(env) + 1);
    if (!new_env)
	{
		error_msg(MLC_ERROR);
        return (NULL);
	}
    while (env[++i])
	{
        new_env[i] = ft_strdup(env[i]);
	}
	new_env[i] = NULL;
	return (new_env);
}

void	env_command(char **args)
{
    int    i;
    if (args[1])
        return ;
    i = -1;
    while (data()->env[++i])
        ft_printf("%s\n", data()->env[i]);
}
