/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:51 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 15:12:43 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	do_export2(char *str, int last, char **temp_env)
{
	int	k;

	k = export_exists(str, last);
	if (k == last)
	{
		ft_free_mtx(data()->env);
		(data()->env) = cpy_env(temp_env, str);
		last++;
	}
	else
	{
		free(data()->env[k]);
		data()->env[k] = ft_strdup(str);
	}
}

int	check_arg(char *str)
{
	int	i;

	i = -1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (error_msg(INVALID_EXPORT_ERROR));
	while (str[++i] && str[i] != '=')
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (error_msg(INVALID_EXPORT_ERROR));
	return (0);
}

void	do_export(char **args, int last)
{
	char	**temp_env;
	char	*temp;
	int		j;

	j = 0;
	while (args[++j])
	{
		if (check_arg(args[j]))
			continue ;
		temp_env = cpy_env(data()->env, NULL);
		if (ft_strchr(args[j], '='))
			do_export2(args[j], last, temp_env);
		else
		{
			temp = ft_strjoin(args[j], "=''");
			do_export2(temp, last, temp_env);
			free(temp);
		}
		ft_free_mtx(temp_env);
	}
}

void	export_command(char **args)
{
	int		last;

	if (!args[1])
	{
		export_simple();
		return ;
	}
	last = 0;
	while (data()->env[last])
		last++;
	do_export(args, last);
}
