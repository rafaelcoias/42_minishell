/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:51 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 19:48:35 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    export_command_simple(void)
{
	int i;

	i = 0;
	while (data()->env[i])
	{
		while (data()->env[i] && !ft_strchr(data()->env[i], '='))
			i++;
		if (ft_strchr(data()->env[i], '='))
			ft_printf("%s\n", data()->env[i]);
		i++;
	}
}

int	export_exists(char *str, int last)
{
	char	**split_env;
	char	**split_str;
	char	*temp_str;
	char	*temp_env;
	int		j;

	j = -1;
	split_str = ft_split(str, '=');
	temp_str = split_str[0];
	while (data()->env[++j])
	{
		split_env = ft_split(data()->env[j], '=');
		temp_env = split_env[0];
		if (ft_equals(temp_env, temp_str))
		{
			ft_free_mtx(split_env);
			ft_free_mtx(split_str);
			return (j);
		}
		ft_free_mtx(split_env);
	}
	ft_free_mtx(split_str);
	return (last);
}

void	do_export(char **args, int last, char **temp_env)
{
	int	k;
	int	j;

	j = -1;
	while (args[++j])
	{
		if (ft_strchr(args[j], '='))
		{
			k = export_exists(args[j], last);
			if (k == last)
			{
				ft_free_mtx(data()->env);
				data()->env = cpy_env_new(temp_env, args[j]);
				last++;
			}
			else
			{
				free(data()->env[k]);
				data()->env[k] = ft_strdup(args[j]);
			}
		}
	}
}

void    export_command(char **args)
{
	char	**temp_env;
	int     last;

	last = 0;
	if (!args[1])
		export_command_simple();
	while (data()->env[last])
		last++;
	temp_env = cpy_env(data()->env);
	do_export(args, last, temp_env);
	ft_free_mtx(temp_env);
}
