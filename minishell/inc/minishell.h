/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:16:30 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/19 16:24:13 by gseco-lu         ###   ########.fr       */
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
# define CTRL_C_VALUE "130"
# define CTRL_SLASH_VALUE "131"
# define CMD_NOT_FOUND_VALUE "127"

/* ERROR */

# define ERROR "Error : "
# define PIPE_ERROR "Creating pipe"
# define FORK_ERROR "Creating process"
# define MLC_ERROR "Allocation failed"
# define EXEC_ERROR "Invalid command"
# define DIR_ERROR "Directory does not exists"
# define FILE_IS_DIR_ERROR "File cannot be a directory"
# define FILE_ERROR "File does not exists"
# define OPEN_ERROR "Can not open file or directory"
# define FEW_ARGS_ERROR "Not enough arguments"
# define MANY_ARGS_ERROR "Too many arguments"
# define UNSET_ERROR "Invalid parameter name"
# define NO_MATCHES_ERROR "No matches found"
# define EXIT_ARGS_ERROR "Numeric argument requi"
# define INVALID_EXPORT_ERROR "Invalid identifier found"

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
void	free_tokens(void);

/* HANDLE COMMAND */

char	*get_path(char *cmd, char *path);
int		create_commands(void);
int		handle_pipe(void);
int		execute(void);

/* BUILTINS */

int		is_builtin(char *cmd);
int		check_builtins(t_cmd *cmd);
int		forked_builtins(t_cmd *cmd);

/* COMMANDS */

void	pwd_command(char **args);
void	echo_command(char **args);
void	cd_command(char **args);
void	export_command(char **args);
void	env_command(char **args);
void	unset_command(char **args);
void	exit_command(char **args);
int		create_files(t_cmd *cmd);
int		redirections(t_cmd *cmd);

/* HANDLE ENV */

char	*my_getenv(char *str);
char	**cpy_env(char **env, char *new);
char	*expand_env(char *str);
void	export_simple(void);

/* SIGNALS */

void	signal_handler(void);
void	signal_handler_block(void);
void	sig_handler_block(int x);

/* FREE */

void	free_tokens(void);
int		free_cmds(void);

#endif
