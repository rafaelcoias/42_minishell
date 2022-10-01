/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:16:30 by rade-sar          #+#    #+#             */
/*   Updated: 2022/10/01 22:44:30 by rade-sar         ###   ########.fr       */
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

# define PROMPT "minishell ~ "

/* ERROR	*/



/*	LISTS	*/

typedef struct s_data
{
	char	*command;
}	t_data;


/*	FUNCTIONS */

void	read_command(char *command);

#endif
