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

char	*my_getenv(char *str)
{
	char	**split_env;
	char	*result;
	char	*temp_env;
	int		j;

	j = -1;
	if (!str[0])
		return (data()->error);
	while (data()->env[++j])
	{
		split_env = ft_split(data()->env[j], '=');
		temp_env = split_env[0];
		if (ft_equals(temp_env, str))
		{
			result = &data()->env[j][ft_strlen(split_env[0]) + 1];
			ft_free_mtx(split_env);
			return (result);
		}
		ft_free_mtx(split_env);
	}
	return (NULL);
}

char	**cpy_env(char **env, char *new)
{
	char	**new_env;
	int		i;

	i = -1;
	if (new)
		new_env = malloc(sizeof(char *) * ft_mtxlen(env) + 2);
	else
		new_env = malloc(sizeof(char *) * ft_mtxlen(env) + 1);
	if (!new_env)
	{
		error_msg(MLC_ERROR);
		return (NULL);
	}
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	if (new)
		new_env[i++] = ft_strdup(new);
	new_env[i] = NULL;
	return (new_env);
}

void	env_command(char **args)
{
	char	**temp;
	int		i;
	
	if (args[1])
		return ;
	i = -1;
	while (data()->env[++i])
	{
		temp = ft_split(data()->env[i], '=');
		if (temp[1] && !ft_equals(temp[1], "''"))
			ft_printf("%s\n", data()->env[i]);
		ft_free_mtx(temp);
	}
}
