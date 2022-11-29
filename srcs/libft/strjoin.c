/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:18:53 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 16:19:12 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final_line;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	final_line = malloc(sizeof(char) * (__strlen(s1) + __strlen(s2) + 1));
	if (!final_line)
		return (0);
	while (s1[i])
	{
		final_line[i] = s1[i];
		i++;
	}
	while (s2[j])
		final_line[i++] = s2[j++];
	final_line[i] = 0;
	return (free(s1), final_line);
}
