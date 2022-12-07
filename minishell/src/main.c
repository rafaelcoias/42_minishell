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

// Allocar envp

static void init_all(char **envp)
{
	data()->envp = envp;
	data()->exit = 0;
	data()->npipes = 0;
	data()->pwd = malloc(sizeof(t_pwd));
	data()->home_path = getenv("HOME");
	data()->pwd->last = NULL;
	data()->pwd->pwd = data()->home_path;
	data()->pwd->next = NULL;
	get_env_path();
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
	init_all(envp);
	while (!data()->exit)
	{
		data()->npipes = 0;
		input = readline(PROMPT);
		if (input && !ft_strncmp(input, EXIT_CMD, 4))
			exit(0);
		add_history(input);
		if (input && !parser(input) && !create_commands())
			execute();
		free_all(input);
	}
	return (0);
}
