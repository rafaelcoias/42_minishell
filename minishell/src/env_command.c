/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseco-lu <gseco-lu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:49:49 by rade-sar          #+#    #+#             */
/*   Updated: 2022/11/15 20:30:35 by gseco-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    set_pwd(char    *pwd)
{
    int i;
    
    i = 0;  
    while (data()->envp)
    {
        while (data()->envp[i][0] != 'O' && data()->envp[i][1] != 'L')
            i++;
        data()->envp[i] = pwd;
    }
}

void    env_command()
{
    int     i;
    
    i = 0;
    while (data()->envp)
    {
        while (data()->envp[i][0] != 'O' && data()->envp[i][1] != 'L')
            i++;
        data()->envp[i] = data()->oldpwd;
        set_pwd(getenv("PWD"));
    }
}

