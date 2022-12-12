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

int	check_env(char *str, int i)
{
	if (str[i] && (str[i] < 'a' || str[i] > 'z')
		&& (str[i] < 'A' || str[i] > 'Z')
		&& (str[i] < '0' || str[i] > '9'))
		return (0);
	return (1);
}

char	*get_env_var(int *z, char *str)
{
	char	**env;
	char	temp[BUFFER];
	int		i;
	int		j;
	
	i = -1;
	j = -1;
	while (str[++i] && check_env(str, i))
		temp[i] = str[i];
	temp[i] = '\0';
	while (data()->env[++j])
	{
		env = ft_split(data()->env[j], '=');
		if (!ft_equals(env[0], temp))
		{
			ft_free_mtx(env);
			continue ;
		}
		ft_free_mtx(env);
		*z = ft_strlen(temp);
		return (getenv(temp));
	}
	return (NULL);
}

char	*do_trim(char c, char *result)
{
	char	*trim;

	if (c == '\"')
		trim = ft_strtrim(result, "\"");
	else if (c == '\'')
		trim = ft_strtrim(result, "\'");
	else
		trim = ft_strdup(result);
	return (trim);
}

char	*do_expand(char *result, int k, char *str)
{
	char	**all_vars;
	char	*env_var;
	int		j;
	int		i;
	int		z;

	i = -1;
	all_vars = ft_split(str, '$');
	while (all_vars[++i])
	{
		j = -1;
		z = 0;
		env_var = get_env_var(&z, all_vars[i]);
		while (env_var && env_var[++j])
			result[k++] = env_var[j];
		while (env_var && all_vars[i][z])
			result[k++] = all_vars[i][z++];
	}
	result[k] = '\0';
	ft_free_mtx(all_vars);
	return (do_trim(str[0], result));
}

char	*expand_env(char *str)
{
	char	result[BUFFER];
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (str[i] == '\'')
		return (ft_strtrim(str, "\'"));
	while (str[i])
	{
		if (str[i] == '$' && check_env(&str[i + 1], 0))
			return (do_expand(result, k, &str[i]));
		result[k++] = str[i++];
	} 
	result[k] = '\0';
	return (do_trim(str[0], result));
}
