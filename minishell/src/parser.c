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
	while (input[j] && input[j] != c)
	{
		str[i] = input[j];
		i++;
		j++;
	}
	str[i] = '\0';
	*token = str;
	return (j);
}

int	handle_quotes(char *input, char **token)
{
	if (input[0] == '\"')
		return (check_quotes(input, token,'\"', 1));
	else if (input[0] == '\'')
		return (check_quotes(input, token, '\'', 1));
	else
		return (check_quotes(input, token, ' ', 0));
}

t_token	*handle_allocation(char *s)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	if (s)
		new->word = s;
	new->next = NULL;

	return (new);
}

int    parser(char *input)
{
	int     i;
	int     ti;
	char    *token[BUFFER];
	t_token	*tmp;
	t_token	*first;
	
	i = 0;
	ti = 0;
	tmp = NULL;
	first = handle_allocation("teste");
	if (!first)
		return (error_msg(MLC_ERROR));
	first->next = tmp;
	tmp = first;
	while (input[i])
	{
		while (input[i] && (input[i] == ' ' || input[i] == '\t'))
			i++;
		i = i + handle_quotes(&input[i], &token[ti]);
		tmp->next = handle_allocation("");
		if (!tmp->next)
			return (error_msg(MLC_ERROR));
		tmp = tmp->next;
		tmp->word = token[ti];
		ti++;
		i++;
	}
	tmp->next = NULL;
	data()->token = first;
	printf("%s\n", data()->token->word);
	printf("%s\n", data()->token->next->word);
	printf("AQUI");
	return (0);
}

//int	main(int argc, char **argv)
//{
//	parser(argv);
//}