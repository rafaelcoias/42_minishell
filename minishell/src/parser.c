/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:26:20 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/11 19:26:20 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	handle_quotes(char *input, char **token)
{
	char	str[BUFFER];
	int		i;
	char	c;

	i = 0;
	while (input[i] && input[i] != ' ')
	{
		c = input[i];
		if (c != '\'' && c != '\"')
			c = ' ';
		else
			str[i++] = c;
		while (input[i] && input[i] != c)
		{
			str[i] = input[i];
			i++;
		}
		if (input[i] && (c == '\'' || c == '\"'))
			str[i] = c;
	}
	str[i] = '\0';
	*token = str;
	return (i);
}

int	parser(char	*input)
{
	int		i;
	int		ti;

	i = 0;
	ti = 0;
	while (input[i])
	{
		while (input[i] && (input[i] == ' ' || input[i] == '\t'))
			i++;
		if (!input[i])
			break ;
		i = i + handle_quotes(&input[i], &data()->token[ti]) - 1;
		data()->token[ti] = ft_strdup(data()->token[ti]);
		ti++;
		if (!input[i])
			break ;
		i++;
	}
	data()->token[ti] = NULL;
	return (0);
}
