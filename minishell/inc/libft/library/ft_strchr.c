/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:06:00 by rade-sar          #+#    #+#             */
/*   Updated: 2022/07/13 00:32:10 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	lt;

	lt = c;
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == lt)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && lt == '\0')
		return ((char *)s);
	return (NULL);
}
