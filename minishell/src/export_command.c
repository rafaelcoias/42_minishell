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
			free(data()->env[j]);
			return (j);
		}
		ft_free_mtx(split_env);
	}
	ft_free_mtx(split_str);
	return (last);
}

void    export_command(char **args)
{
	int     last;
	int		j;
	int		k;

	last = 0;
	j = 0;
	if (!args[1])
		export_command_simple();
	while (data()->env[last])
		last++;
	while (args[++j])
	{
		if (ft_strchr(args[j], '='))
		{
			k = export_exists(args[j], last);
			ft_free_mtx(data()->env);
			data()->env[k] = ft_strdup(args[j]);
			if (k == last)
				last++;
		}
	}
	data()->env[last] = NULL;
}
