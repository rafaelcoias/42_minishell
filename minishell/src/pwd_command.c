/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:56 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 15:26:57 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//	Handle the pwd command

void	pwd_command(char **args)
{
	char	path[BUFFER];

	if (args[1])
		return ((void)error_msg(MANY_ARGS_ERROR));
	getcwd(path, BUFFER);
	ft_printf("%s\n", path);
}
