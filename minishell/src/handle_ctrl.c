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

void	sigint_handler(int x)
{
	(void)x;
	ft_printf("\n%s", PROMPT);
}

void	sigtstp_handler(int x)
{
	(void)x;
}

void	signal_handler(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGTSTP, sigtstp_handler);
	signal(SIGQUIT, SIG_IGN);
}
