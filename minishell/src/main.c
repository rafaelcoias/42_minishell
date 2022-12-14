/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:10:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/14 15:34:16 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// A fazer

// ctrl-C faz prompt 2x do Prompt
// Perceber porque $TESTE = t => ca$TESTE nao funciona como cat
// Exit tem de dar um valor no $? ?
// unset path
// leaks quando se da export de uma variavel e depois se chama 

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

char	*get_prompt(void)
{
	char	path[BUFFER];
	char	*prompt;
	char	**split_pwd;
	char	*temp;

	getcwd(path, BUFFER);
	split_pwd = ft_split(path, '/');
	temp = split_pwd[ft_mtxlen(split_pwd) - 1];
	temp = ft_strjoin(CYAN, temp);
	prompt = ft_strjoin(temp, RED);
	free(temp);
	temp = ft_strjoin(prompt, " ~ ");
	free(prompt);
	prompt = ft_strjoin(temp, RESET);
	free(temp);
	ft_free_mtx(split_pwd);
	return (prompt);
}

void	init_all(void)
{
	data()->exit = 0;
	data()->npipes = 0;
	data()->prompt = get_prompt();
	data()->home_path = my_getenv("HOME");
}

void	exit_program(char *input)
{
	(void)input;
	exit(0);
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
 *	If user writes the exit command or CTRL-D,
 *	the program frees everything and ends.
 * */
int	main(int argc, char **argv, char **envp)
{
	char		*input;

	(void)argc;
	(void)argv;
	signal_handler();
	data()->env = cpy_env(envp, NULL);
	data()->error = NONE;
	while (!data()->exit)
	{
		init_all();
		input = readline(data()->prompt);
		if (input && !ft_strncmp(input, EXIT_CMD, 4))
			exit_program(input);
		add_history(input);
		if (input && !parser(input) && !create_commands())
			execute();
		if (!input)
			break ;
		free_all(input);
	}
	ft_free_mtx(data()->env);
	return (0);
}
