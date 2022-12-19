/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:47 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/19 16:22:10 by gseco-lu         ###   ########.fr       */
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

void	print_args(char **args, int i)
{
	while (args[i] && !ft_equals(args[i], ">")
		&& !ft_equals(args[i], ">>")
		&& !ft_equals(args[i], "<")
		&& !ft_equals(args[i], "<<"))
	{
		if (args[i + 1])
			ft_printf("%s ", args[i++]);
		else
			ft_printf("%s", args[i++]);
	}
}

void	echo_command(char **args)
{
	int	i;

	i = 1;
	if (args[i] && !ft_strcmp(args[i], "-n"))
		print_args(args, ++i);
	else
	{
		print_args(args, i);
		ft_putchar_fd('\n', 1);
	}
}
