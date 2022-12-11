/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:16:30 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 19:42:21 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*	INCLUDES	*/

# include "./libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

/*	DEFINES */

# define BUFFER 1024
# define PROMPT CYAN"minishell"RED" ~ "RESET
# define PWD_CMD "pwd"
# define ECHO_CMD "echo"
# define EXIT_CMD "exit"
# define CD_CMD "cd"
# define EXPORT_CMD "export"
# define ENV_CMD "env"
# define UNSET_CMD "unset"

/* ERROR	*/

# define PIPE_ERROR RED"Error : "YELLOW"Creating pipe"RESET
# define FORK_ERROR RED"Error : "YELLOW"Creating process"RESET
# define MLC_ERROR RED"Error : "YELLOW"Allocation failed"RESET
# define EXEC_ERROR RED"Error : "YELLOW"Invalid command"RESET
# define DIR_ERROR RED"Error : "YELLOW"Directory does not exists"RESET
# define OPEN_ERROR RED"Error : "YELLOW"Can not open file or directory"RESET

/*	LISTS	*/

typedef struct s_cmd
{
	char			*path;
	char			*args[BUFFER];
	char			*exec_args[BUFFER];
	pid_t			pid;
	int				pipe[2];
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	char	*home_path;
	char	**env;
	char	**env_path;
	int		npipes;
	int		exit;
	int		fd_heredoc;
	char	*token[BUFFER];
	t_cmd	*cmd;
}	t_data;

/*	FUNCTIONS */

/* MAIN */

t_data	*data(void);
int		parser(char *input);
char	*expand_env(char *str);
int		error_msg(char *str);
void	free_all(char *input);

/* HANDLE COMMAND */

int		create_commands(void);
int		handle_pipe(void);
void	check_builtins(t_cmd *cmd);
int		execute(void);

/* COMMANDS */

void	pwd_command(void);
void	echo_command(char **args);
void	cd_command(char **args);
void	env_command(char **args);
char	**cpy_env(char **env);
void    export_command(char **args);
void	redirections(t_cmd *cmd);

/* SIGNALS */

void	signal_handler(void);

#endif
