/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/10 12:53:39 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sig_handler_block(int x)
{
	if (x == SIGINT)
	{
		write(1, "\n", 1);
		data()->error = CTRL_C_VALUE;
	}
	else if (x == SIGQUIT)
	{
		write(1, "Quit (core dumped)\n", 19);
		rl_on_new_line();
		rl_replace_line("", 0);
		data()->error = CTRL_SLASH_VALUE;
	}
}

void	signal_handler_block(void)
{
	signal(SIGINT, sig_handler_block);
	signal(SIGQUIT, sig_handler_block);
}

void	sig_handler(int x)
{
	if (x == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		data()->error = CTRL_C_VALUE;
	}
	else if (x == SIGTSTP)
		data()->error = CTRL_SLASH_VALUE;
}

void	signal_handler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
