/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:05 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 16:12:44 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			tmp_length(char	*tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	free(tmp);
	return (i);
}

int			line_map_length(char *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[j] && tmp[j] == ' ')
			j++;
		if (tmp[j] && tmp[j] != '\n')
			i = i + j;
		else
			return (i);
		i++;
	}
	return (i);
}