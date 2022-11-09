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

typedef struct s_data
{
	char	**envp;
	char	**env_path;
	char	**pipes;
	int	pipe_fd[2];
	int	infile_fd;
	int	outfile_fd;
	char	**cmd;
	char	*cmd_path;
	int		cmd_index;
	char	*home_path;
	int	exit;
}	t_data;


/*	FUNCTIONS */

/* MAIN */

void	read_command(t_data *data);
int	error_msg(char *str);

/* HANDLE COMMAND */

char*	get_cmd_path(t_data *data);
int	handle_pipe(t_data *data);

/* COMMANDS */

void	pwd_command();
void	echo_command(t_data *data);

#endif
