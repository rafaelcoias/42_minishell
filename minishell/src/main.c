/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:10:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 17:45:05 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

// Saves all command paths

static void	get_env_path(void)
{
	char	*path;

	path = getenv("PATH");
	data()->env_path = ft_split(&path[5], ':');
}

/*	Free everything in data list
	And frees input
 */

void	free_all(char *input)
{
	t_cmd	*aux;
	t_cmd	*temp;

	aux = data()->cmd;
	while (aux)
	{
		temp = data()->cmd->next;
		//ft_free_mtx(aux->args);
		free(aux->path);
		free(aux);
		aux = temp;
	}
	free(input);
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
 *	If user writes the exit command, the program frees
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
	data()->home_path = getenv("HOME");
	get_env_path();
	while (!data()->exit)
	{
		input = readline(PROMPT);
		add_history(input);
		if (!parser(input) && !create_commands())
			execute();
		free_all(input);
	}
	return (0);
}
