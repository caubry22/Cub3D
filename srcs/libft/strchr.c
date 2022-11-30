/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:32:08 by caubry            #+#    #+#             */
/*   Updated: 2022/11/30 17:08:12 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = __strlen(s);
	while (i <= j)
	{
		if ((unsigned char)s[j - i] == (unsigned char)c)
			return ((char *)s + (j - i));
		i++;
	}
	return (0);
}
