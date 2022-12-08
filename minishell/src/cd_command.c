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
	if (!args[1])
		chdir(data()->home_path);
	else
		if (chdir(args[1]))
			return ((void)error_msg(DIR_ERROR));
}
