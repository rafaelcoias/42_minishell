/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:16:30 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/12 00:45:33 by rade-sar         ###   ########.fr       */
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

# define CMD_ERROR RED"Error : "YELLOW"Invalid command"RESET
# define PIPE_ERROR RED"Error : "YELLOW"Creating pipe"RESET
# define FORK_ERROR RED"Error : "YELLOW"Creating fork"RESET
# define EXEC_ERROR RED"Error : "YELLOW"Executing command"RESET

/*	LISTS	*/

typedef struct s_cmd
{
	char	*path;
	char	**args;
	int		cmd_index;
	int		fd[2];
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	char	*home_path;
	char	**envp;
	char	**env_path;
	char	**pipes;
	int		exit;
	t_cmd	*cmd;
}	t_data;


/*	FUNCTIONS */

/* MAIN */

t_data	*data();
void	read_command(t_data *data);
int		error_msg(char *str);

/* HANDLE COMMAND */

char*	get_cmd_path(t_data *data);
int	handle_pipe(t_data *data);

/* COMMANDS */

void	pwd_command();
void	echo_command(t_data *data);

/* SIGNALS */

void    signal_handler();

#endif
