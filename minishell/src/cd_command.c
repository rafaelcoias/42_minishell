/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:39 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 19:50:43 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	cd_command(char **args)
{
	t_pwd	*last_pwd;

	if (!args[1])
		chdir(data()->home_path);
	else
	{
		last_pwd = data()->pwd;
		data()->pwd->next = malloc(sizeof(t_pwd));
		data()->pwd = data()->pwd->next;
		data()->pwd->last = last_pwd;
		if (chdir(args[1]))
			error_msg(DIR_ERROR);
		data()->pwd->pwd = getenv("PWD");
		data()->pwd->next = NULL;
	}
}
