/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:56 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/11 10:49:47 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//	Handle the pwd command

void	pwd_command(void)
{
	char	path[BUFFER];

	getcwd(path, BUFFER);
	ft_printf("%s\n", path);
	exit(0);
}
