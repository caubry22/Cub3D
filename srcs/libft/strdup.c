/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:09:49 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 16:09:50 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*final_str;

	i = 0;
	while (s1[i])
		i++;
	final_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(final_str))
		return (0);
	i = 0;
	while (s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}
	final_str[i] = 0;
	return (final_str);
}
