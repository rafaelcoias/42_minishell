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

int	check_error_value(char *str, int value)
{
	int	num;
	int	i;

	i = 0;
	if (!str[0])
	{
		num = ft_atoi(str);
		if (num == 0)
			return (1);
		while (num != 0)
		{
			num /= 10;
			i++;
		}
		return (i);
	}
	return (value);
}

char	*get_env_var(int *z, char *str)
{
	char	**env;
	char	temp[BUFFER];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (str[++i] && ft_isalnum(str[i]))
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
		break ;
	}
	*z = ft_strlen(temp);
	*z = check_error_value(temp, *z);
	return (my_getenv(temp));
}

int	do_expand(char *result, int k, char *str, int *str_i)
{
	char	**all_vars;
	char	*env_var;
	int		j;
	int		z;

	all_vars = ft_split(str, '$');
	if (all_vars[0])
	{
		j = -1;
		z = 0;
		env_var = get_env_var(&z, all_vars[0]);
		while (env_var && env_var[++j])
			result[k++] = env_var[j];
		while (all_vars[0][z] && all_vars[0][z] != '\"')
			result[k++] = all_vars[0][z++];
		*str_i = *str_i + z;
	}
	ft_free_mtx(all_vars);
	return (k);
}

int	handle_double_quote(char *result, char *str, int *i, int k)
{
	if (str[*i] && str[*i] == '$' && (ft_isalnum(str[*i + 1])
		|| str[*i + 1] == '?'))
		k = do_expand(&result[0], k, &str[*i], i);
	else
		result[k++] = str[*i];
	return (k);
}

char	*expand_env(char *str)
{
	char	result[BUFFER];
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			while (str[++i] && str[i] != '\'')
				result[k++] = str[i];
		else if (str[i] && str[i] == '\"')
			while (str[++i] && str[i] != '\"')
				k = handle_double_quote(&result[0], str, &i, k);
		else
			k = handle_double_quote(&result[0], str, &i, k);
		i++;
	}
	result[k] = '\0';
	return (ft_strdup(result));
}
