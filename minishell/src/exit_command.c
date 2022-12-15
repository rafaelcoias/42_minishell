/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:10:15 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 17:10:17 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	do_exit_value(long long num)
{
	if (num >= 0)
	{
		if (num >= 0 && num < 255)
			return ((int)num);
		while (num > 255)
			num = num - 256;
		return ((int)(num));
	}
	if (num <= 0 && num >= -256)
		return ((int)(256 + num));
	while (num < -256)
		num = num + 256;
	return ((int)(256 + num));
}

void	exit_command(char **args)
{
	long long	tmp;
	int			status;

	printf("exit\n");
	if (ft_mtxlen(args) > 2 && !is_num(args[ft_mtxlen(args) - 1]))
		return ((void)error_msg(MANY_ARGS_ERROR));
	if (args[1])
	{
		tmp = ft_atol(args[1]);
		if (!is_num(args[1]))
		{
			error_msg(EXIT_ARGS_ERROR);
			status = 2;
		}
		else if (tmp == 0)
			status = 0;
		else
			status = do_exit_value(tmp);
	}
	else
		status = ft_atoi(data()->error);
	exit(status);
}
