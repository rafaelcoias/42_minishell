/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:57 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/10 12:53:25 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	unset_command(char **args)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	int		x;
// 	char	*s;

// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	s = args[0];
// 	len = ft_strlen(s);
// 	while (data()->env[i])
// 	{
// 		while (data()->env[i][j] != s[x] && data()->env[i][j])
// 			i++;
// 		while (data()->env[i][j] == s[x]
// 			&& data()->env[i][j] && j < len && s[x])
// 		{
// 			j++;
// 			x++;
// 			if (j != len - 1)
// 			{
// 				x = 0;
// 				j = 0;
// 				i++;
// 			}
// 			else
// 				free(data()->env[i]);
// 		}
// 		while (data()->env[i + 1])
// 		{
// 			data()->env[i] = data()->env[i + 1];
// 			i++;
// 		}
// 		data()->env[i] = NULL;
// 	}
// }
