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

void	check_quotes(char *input, char **token, char c)
{
	char	str[BUFFER];
	int		i;

	i = 1;
	while (input[i] && input[i] != c)
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	*token = str;
}

void	handle_quotes(char *input, char **token)
{
	if (input[0] == '\"')
		check_quotes(input, token,'\"');
	else if (input[0] == '\'')
		check_quotes(input, token, '\'');
	else
		check_quotes(input, token, ' ');
}

void    parser(char *input)
{
	int     i;
	int     ti;
	char    *token[BUFFER];
	t_token	*tmp;
	int		first;
	
	i = 0;
	ti = 0;
	first = 1;
	tmp = data()->token;
	while (input[i])
	{
		while (input[i] && (input[i] == ' ' || input[i] == '\t'))
			i++;
		handle_quotes(&input[i], &token[ti]);
		data()->token = malloc(sizeof(t_token));
		data()->token->word = token[ti];
		if (first)
		{
			tmp = data()->token;
			first = 0;
		}
		data()->token = data()->token->next;
		ti++;
		i++;
	}
	data()->token = tmp;
}

//int	main(int argc, char **argv)
//{
//	parser(argv);
//}
