/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ctrl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/15 18:38:13 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sig_handler_block(int x)
{
	if (x == 2)
	{
		write(1, "\naaaa", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		data()->error = CTRL_C_VALUE;
	}
	else if (x == 131)
	{
		write(1, "Quit (core dumped)\n", 19);
		rl_on_new_line();
		rl_replace_line("", 0);
		data()->error = CTRL_SLASH_VALUE;
	}
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
