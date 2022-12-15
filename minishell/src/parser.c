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

int	check_quotes(char *input, char **token, char c, int j)
{
	char	str[BUFFER];
	int		i;

	i = 0;
	if (c != ' ')
		str[i++] = c;
	while (input[j] && (input[j] != c))
	{
		if (input[j] && input[j + 1] && (input[j] == '\\') && (input[j + 1] != '\\'))
				j++;
		str[i++] = input[j++];
	}
	while (input[j] && input[j] != ' ')
	{
		if (input[j] && input[j + 1] && (input[j] == '\\') && (input[j + 1] != '\\'))
				j++;
		str[i++] = input[j++];
	}	
	if (input[j] && input[j + 1] && (input[j] == '\\') && (input[j + 1] != '\\'))
				j++;
	if (input[j] != ' ')
		str[i++] = input[j++];
	str[i] = '\0';
	*token = str;
	return (j);
}

int	handle_quotes(char *input, char **token)
{
	if (input[0] == '\"')
		return (check_quotes(input, token, '\"', 1));
	else if (input[0] == '\'')
		return (check_quotes(input, token, '\'', 1));
	else
		return (check_quotes(input, token, ' ', 0));
}

int	parser(char	*input)
{
	int	i;
	int	ti;

	i = 0;
	ti = 0;
	while (input[i])
	{
		while (input[i] && (input[i] == ' ' || input[i] == '\t'))
			i++;
		i = i + handle_quotes(&input[i], &data()->token[ti]);
		data()->token[ti] = ft_strdup(data()->token[ti]);
		ti++;
		i++;
	}
	data()->token[ti] = NULL;
	return (0);
}
