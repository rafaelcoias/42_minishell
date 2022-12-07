/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:47 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/11 23:17:35 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

	// while (str[++i] && (str[i] >= 'a' && str[i] <= 'z')
	// 	|| (str[i] >= 'A' && str[i] <= 'Z')
	// 	|| (str[i] >= '0' && str[i] <= '9'))
	// 	env[i] = str[i];

char	*get_env_var(char *str)
{
	char	**env;
	int		i;

	i = -1;
	while (data()->env_path[++i])
	{
		env = ft_split(data()->env_path[i], '=');
		if (!ft_equals(env[0], str))
		{
			ft_free_mtx(env);
			continue ;
		}
		return (getenv(str));
	}
	return (NULL);
}

int	check_env(char *str)
{
	if (str[0] && (str[0] < 'a' || str[0] > 'z')
		&& (str[0] < 'A' || str[0] > 'Z')
		&& (str[0] < '0' || str[0] > '9'))
		return (0);
	return (1);
}

char	*expand_env(char *str)
{
	char	result[BUFFER];
	char	*trim;
	char	*env_var;
	int		i;
	int		j;

	i = 0;
	//printf("AQUI : %s\n", result);
	if (str[i] == '\'')
		return (str);
	while (str[i])
	{
		if (str[i] == '$' && check_env(&str[i + 1]))
		{
			env_var = get_env_var(&str[i + 1]);
			j = -1;
			while (env_var[++j])
				result[i++] = env_var[j];
		}
		else
			result[i] = str[i];
		//printf("result[%i] : %s\n", i, result);
		i++;
	}
	result[i] = '\0';
	trim = result;
	if (str[0] == '\'')
		trim = ft_strtrim(result, "\'");
	else if (str[0] == '\"')
		trim = ft_strtrim(result, "\"");
	else
		trim = ft_strdup(result);
	return (trim);
}
