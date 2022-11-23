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

/*	Handle the echo command 
 *	
 *	If there is the -n option
 *	it doesn't display a new line
 *	at the end.
 *
 *	*/

void	echo_command(char **args)
{
	int	i;

	i = 1;
	if (args[i] && !ft_strcmp(args[i], "-n"))
	{
		i++;
		while (args[i])
			ft_printf("%s ", args[i++]);
	}
	else
	{
		while (args[i])
			ft_printf("%s ", args[i++]);
		ft_putchar_fd('\n', 1);
	}
}
