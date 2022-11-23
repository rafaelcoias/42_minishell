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

// void	set_pwd(char	*pwd)
// {
// 	int	i;

// 	i = 0;
// 	data()->env_path = getent();
// 	while (data()->env_path)
// 	{
// 		while (data()->env_path[i][0] != 'O' && data()->env_path[i][1] != 'L')
// 			i++;
// 		data()->env_path[i] = pwd;
// 	}
// }

// void	env_command(void)
// {
// 	int	i;

// 	i = 0;
// 	while (data()->envp)
// 	{
// 		while (data()->env_path[i][0] != 'O' && data()->env_path[i][1] != 'L')
// 			i++;
// 		data()->env_path[i] = data()->oldpwd;
// 		set_pwd(getenv("PWD"));
// 	}
// }

