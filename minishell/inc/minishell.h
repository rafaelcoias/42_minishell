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

/* INCLUDES	*/

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

/* DEFINES */

# define BUFFER 1024
# define PWD_CMD "pwd"
# define ECHO_CMD "echo"
# define EXIT_CMD "exit"
# define CD_CMD "cd"
# define EXPORT_CMD "export"
# define ENV_CMD "env"
# define UNSET_CMD "unset"

/* EXIT VALUES */

# define NONE "0"
# define NORMAL_ERROR_VALUE "1"
# define OUT_RANGE_VALUE "255"
# define CTRL_C_VALUE "130"
# define CMD_NOT_FOUND_VALUE "127"

/* ERROR */

# define PIPE_ERROR RED"Error : "YELLOW"Creating pipe"RESET
# define FORK_ERROR RED"Error : "YELLOW"Creating process"RESET
# define MLC_ERROR RED"Error : "YELLOW"Allocation failed"RESET
# define EXEC_ERROR RED"Error : "YELLOW"Invalid command"RESET
# define DIR_ERROR RED"Error : "YELLOW"Directory does not exists"RESET
# define FILE_IS_DIR_ERROR RED"Error : "YELLOW"File cannot be a directory"RESET
# define FILE_ERROR RED"Error : "YELLOW"File does not exists"RESET
# define OPEN_ERROR RED"Error : "YELLOW"Can not open file or directory"RESET
# define FEW_ARGS_ERROR RED"Error : "YELLOW"Not enough arguments"RESET
# define MANY_ERROR RED"Error : "YELLOW"Too many arguments"RESET
# define UNSET_ERROR RED"Error : "YELLOW"Invalid parameter name"RESET

/* LISTS */

typedef struct s_cmd
{
	char			*path;
	char			*args[BUFFER];
	char			*exec_args[BUFFER];
	pid_t			pid;
	int				pipe[2];
	int				redir;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	char	*home_path;
	char	*prompt;
	char	**env;
	char	**env_path;
	char	*error;
	int		npipes;
	int		exit;
	int		fd_heredoc;
	char	*token[BUFFER];
	t_cmd	*cmd;
}	t_data;

/* FUNCTIONS */

/* MAIN */

t_data	*data(void);
int		parser(char *input);
int		error_msg(char *str);
void	free_all(char *input);

/* HANDLE COMMAND */

int		create_commands(void);
int		handle_pipe(void);
int		execute(void);

/* BUILTINS */

int		is_builtin(t_cmd *cmd);
int		check_builtins(t_cmd *cmd);
int		forked_builtins(t_cmd *cmd);

/* COMMANDS */

void	pwd_command(char **args);
void	echo_command(char **args);
void	cd_command(char **args);
void	export_command(char **args);
void	env_command(char **args);
void	unset_command(char **args);
int		redirections(t_cmd *cmd);

/* HANDLE ENV */

char	*my_getenv(char *str);
char	**cpy_env(char **env, char *new);
char	*expand_env(char *str);

/* SIGNALS */

void	signal_handler(void);

#endif
