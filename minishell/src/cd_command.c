/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:39 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/15 20:28:08 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	cd_command(char **args)
{
	if (args[1] && chdir(args[1]))
		error_msg(DIR_ERROR);
	else
	{
		data()->oldpwd = getenv("PWD");
		chdir(data()->home_path);
	}
	exit(0);
}
