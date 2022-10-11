/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:10:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/11 11:11:10 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*	Free everything in data list
 * */

void	free_all(t_data *data)
{
	(void)data;
}


/*	When minishell starts it will always ask for
 * the users input.
 *
 *	Then, it splits the input line into pipes. If
 *	there are no pipes it splits into commands.
 *	
 *	Reads the line to check what command was entered
 *	and after executing the command it frees the input
 *	to do all over again.
 *
 *	If user writes the eit command, the program frees
 *	everything and ends.
 * */
int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char		*input;
	
	(void)argc;
	(void)argv;
	data.envp = envp;
	data.exit = 0;
	while (!data.exit)
	{
		input = readline(PROMPT);
		data.pipes = ft_split(input, '|');
		read_command(&data);
		free(input);
	}
	free_all(&data);
	return (0);
}
