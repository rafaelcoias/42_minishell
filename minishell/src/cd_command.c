/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:39 by rade-sar          #+#    #+#             */
/*   Updated: 2022/12/19 14:51:01 by gseco-lu         ###   ########.fr       */
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

char	*handle_home_path(char *path)
{
	char	*home_dir;
	char	*tmp;

	home_dir = my_getenv("HOME");
	if (path[1])
		tmp = ft_strjoin(home_dir, &path[1]);
	else
		tmp = ft_strjoin(home_dir, "/");
	return (tmp);
}

char	*do_cd(char **args)
{
	char	*cd;

	if (!args[1])
		cd = ft_strdup(my_getenv("HOME"));
	else
	{
		if (args[1][0] == '~' && (!args[1][1]
			|| (args[1][1] && args[1][1] == '/')))
			cd = handle_home_path(args[1]);
		else if (ft_equals(args[1], "-"))
			cd = ft_strdup(my_getenv("OLDPWD"));
		else
			cd = ft_strdup(args[1]);
	}
	return (cd);
}

void	cd_command(char **args)
{
	char	path[BUFFER];
	char	oldpwd[BUFFER];
	char	*cd;

	if (ft_mtxlen(args) > 2)
		return ((void)error_msg(MANY_ARGS_ERROR));
	getcwd(oldpwd, BUFFER);
	cd = do_cd(args);
	if (chdir(cd))
	{
		free(cd);
		return ((void)error_msg(DIR_ERROR));
	}
	free(cd);
	if (ft_equals(args[1], "-"))
	{
		getcwd(path, BUFFER);
		ft_printf("%s\n", path);
	}
	export_oldpwd(oldpwd);
	export_pwd();
}
