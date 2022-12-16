/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:49 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 20:07:07 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	organize_alpha(char **env)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (env[++i])
	{
		j = -1;
		while (env[++j + 1 + i])
		{
			if (ft_strcmp(env[j], env[j + 1]) > 0)
			{
				tmp = env[j];
				env[j] = env[j + 1];
				env[j + 1] = tmp;
			}
		}
	}
}

void	export_simple(void)
{
	char	**tmp;
	char	aux[BUFFER];
	int		i;
	int		j;

	i = -1;
	tmp = cpy_env(data()->env, NULL);
	organize_alpha(tmp);
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j] && tmp[i][j] != '=')
			aux[j] = tmp[i][j];
		aux[j++] = '\0';
		if (!ft_strcmp(aux, "_"))
			continue ;
		ft_printf("declare -x %s", aux);
		if (tmp[i][j - 1])
			ft_printf("=\"%s\"\n", &tmp[i][j]);
		else
			ft_printf("\n");
	}
	ft_free_mtx(tmp);
}

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
		if (ft_strchr(data()->env[i], '='))
			ft_printf("%s\n", data()->env[i]);
		ft_free_mtx(temp);
	}
}
