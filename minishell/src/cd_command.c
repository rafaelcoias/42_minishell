// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cd_command.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/01 20:49:39 by rade-sar          #+#    #+#             */
// /*   Updated: 2022/10/10 12:54:22 by rade-sar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../inc/minishell.h"

// int *ft_cd(t_data data)
// {
//     char    *str;
//     int     i;

//     str = get_string(data->cmd[data.cmd_index]);
//     if (str)
//     {
//         if (chdir(str) == 0)
//             chdir(str);
//         else
//             error_msg(CMD_ERROR);
//     }
//     else
//     {
//         str = data.home_path;
//         chdir(str);
//     }


// }

// char    *get_string(char *str)
// {
//     char    *str1;
//     int     i;
//     int     j;
//     int     cd;

//     i = 0;
//     j = 0;
//     cd = 0;
//     while (str[i] != '\0')
//     {
//         if (str[i] == c && str[i + 1] == d && cd == 0)
//         {
//             i = i + 2;
//             cd = 1;
//         }
//         if (str[i] == ' ')
//             i += 1;
//         if (str[i] != c && str[i] != d && str[i] != ' ')
//         {
//             str1[j] = str[i];
//             j += 1;
//             i += 1;
//         }
//     }
//     str1[j] = '\0';
//     return (str1);

// }