/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:10:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/12 00:44:32 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	get_env_path(t_data *data)
{
	char	*path;

	path = getenv("PATH");
	data->env_path = ft_split(&path[5], ':');
}


/*	Free everything in data list
 * */

static void	free_all(t_data *data)
{
	(void)data;
}

t_data	*data()
{
	static t_data	data;
	return (&data);
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
	char		*input;

	(void)argc;
	(void)argv;
	signal_handler();
	data()->envp = envp;
	data()->exit = 0;
	get_env_path(data());
	while (!data()->exit)
	{
		input = readline(PROMPT);
		add_history(input);
		read_command(data());
		free(input);
	}
	free_all(&data);
	return (0);
}
