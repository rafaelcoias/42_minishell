/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:39 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/16 19:50:43 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	export_pwd(void)
{
	char	**args;
	char	*join;
	char	pwd[BUFFER];

	getcwd(pwd, BUFFER);
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("export");
	join = ft_strjoin("PWD=", pwd);
	args[1] = ft_strdup(join);
	args[2] = NULL;
	export_command(args);
	free(join);
	ft_free_mtx(args);
}

void	export_oldpwd(char *oldpwd)
{
	char	**args;
	char	*join;

	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("export");
	join = ft_strjoin("OLDPWD=", oldpwd);
	args[1] = ft_strdup(join);
	args[2] = NULL;
	export_command(args);
	free(join);
	ft_free_mtx(args);
}

void	cd_command(char **args)
{
	char	oldpwd[BUFFER];

	if (data()->npipes)
		return ;
	getcwd(oldpwd, BUFFER);
	if (!args[1])
		chdir(data()->home_path);
	else
	{
		if (ft_equals(args[1], "-"))
			chdir(getenv("OLDPWD"));
		else
			if (chdir(args[1]))
				return ((void)error_msg(DIR_ERROR));
	}
	export_oldpwd(oldpwd);
	export_pwd();
}
