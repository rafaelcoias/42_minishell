/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:21:57 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 15:13:09 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_exit_value(char *str)
{
	if (ft_equals(str, EXEC_ERROR))
		data()->error = CMD_NOT_FOUND_VALUE;
	else
		data()->error = NORMAL_ERROR_VALUE;
}

// Displays a programmed error message
// Saves the exit value $?

int	error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	get_exit_value(str);
	return (1);
}
