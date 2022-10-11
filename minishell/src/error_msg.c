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

// Displays a programmed error message

int	error_msg(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}
