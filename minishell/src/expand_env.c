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

char	*get_env_var(char *str)
{
	char	**env;
	int		i;

	i = -1;
	while (data()->envp[++i])
	{
		env = ft_split(data()->envp[i], '=');
		if (!ft_equals(env[0], str))
		{
			ft_free_mtx(env);
			continue ;
		}
		ft_free_mtx(env);
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

char	*do_trim(char c, char *result)
{
	char	*trim;

	if (c == '\"')
		trim = ft_strtrim(result, "\"");
	else
		trim = ft_strdup(result);
	return (trim);
}

int	get_var_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	return (i);
}

char	*do_expand(char *result, int k, char *str)
{
	char	**all_vars;
	char	*env_var;
	int		j;
	int		i;

	i = -1;
	all_vars = ft_split(str, '$');
	while (all_vars[++i])
	{
		j = -1;
		env_var = get_env_var(all_vars[i]);
		while (env_var && env_var[++j])
			result[k++] = env_var[j];
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
		if (str[i] == '$' && check_env(&str[i + 1]))
			return (do_expand(result, k, &str[i]));
		result[k++] = str[i++];
	} 
	result[k] = '\0';
	return (do_trim(str[0], result));
}
