/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:21:57 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/11 10:50:28 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_exit_value(char *str)
{
	if (ft_equals(str, OPEN_ERROR) || ft_equals(str, FILE_ERROR)
		|| ft_equals(str, FILE_IS_DIR_ERROR) || ft_equals(str, DIR_ERROR))
		data()->exit_value = FILE_DIR_VALUE;
	else if (ft_equals(str, EXEC_ERROR))
		data()->exit_value = CMD_NOT_FOUND_VALUE;
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
