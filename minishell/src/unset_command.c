/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:57 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 15:15:23 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isalnum(str[i]))
			return (error_msg(UNSET_ERROR));
	}
	return (0);
}

void	do_unset(int i)
{
	while (data()->env[i + 1])
	{
		free(data()->env[i]);
		data()->env[i] = ft_strdup(data()->env[i + 1]);
		i++;
	}
	free(data()->env[i]);
	data()->env[i] = NULL;
}

void	unset_command(char **args)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	if (!args[1])
		return ((void)error_msg(FEW_ARGS_ERROR));
	while (args[++j])
	{
		if (check(args[j]))
			continue ;
		i = 0;
		while (data()->env[i])
		{
			temp = ft_split(data()->env[i], '=');
			if (ft_equals(temp[0], args[j]))
				do_unset(i);
			ft_free_mtx(temp);
			i++;
		}
	}
}
