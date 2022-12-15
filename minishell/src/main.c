/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:10:52 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/15 16:39:57 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// A fazer

//// Perceber porque $TESTE = t => ca$TESTE nao funciona como cat

// Exit no minishell 2 da erro
// Ctrl's no minishell 2 esta mal

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

void	update_shlvl(void)
{
	char	**args;
	char	*shlvl;
	char	*new_shlvl;
	int		lvl;
	
	shlvl = my_getenv("SHLVL");
	if (shlvl)
	{
		args = malloc(sizeof(char *) * 3);
		lvl = ft_atoi(shlvl) + 1;
		new_shlvl = ft_itoa(lvl);
		shlvl = ft_strjoin("SHLVL=", new_shlvl);
		free(new_shlvl);
		args[0] = ft_strdup("export");
		args[1] = shlvl;
		args[2] = NULL;
		export_command(args);
		ft_free_mtx(args);
	}	
}

void	init_all(void)
{
	data()->exit = 0;
	data()->npipes = 0;
	data()->prompt = get_prompt();
	data()->home_path = my_getenv("HOME");
	data()->ctrl_control = 1;
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
	(data()->env) = cpy_env(envp, NULL);
	update_shlvl();
	data()->error = NONE;
	while (!data()->exit)
	{
		init_all();
		signal_handler();
		input = readline(data()->prompt);
		add_history(input);
		if (input && !parser(input) && !create_commands())
			execute();
		if (!input)
			break ;
		free_all(input);
	}
	ft_free_mtx(data()->env);
	printf("exit\n");
	return (ft_atoi(data()->error));
}
