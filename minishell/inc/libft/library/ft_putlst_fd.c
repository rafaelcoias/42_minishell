/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:48:54 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/13 04:02:45 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putlst_fd(char **lst, int fd)
{
	int	i;

	if (!lst)
		return ;
	i = 0;
	while (lst[i])
	{
		ft_putstr_fd(lst[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
