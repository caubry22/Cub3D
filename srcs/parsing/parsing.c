#include "../cub3d.h"

bool	check_extension(char *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
		i++;
	tmp = map + i - 4;
	if (ft_strcmp(tmp, ".cub"))
		return (false);
	return (true);
}

static bool	check_map(char *tmp) {
	(void)*tmp;
	return (true);
}

void	init_color(char *tmp, int **color)
{
	int	i;
	int	j;
	int	rgb;

	i = 0;
	rgb = 0;
	while(tmp[i])
	{
		j = 0;
		while (ft_isdigit(tmp[i + j]))
		{
			rgb = rgb * 10 + tmp[i + j] - '0';
			j++;
		}
		color[]
	}
}

static bool	check_colors(char *tmp, int i, t_map *map) {
	const char	*color[2] = {"F ", "C "};
	int			**map_color[2] = {map->color_floor, map->color_ceiling};
	if (ft_strncmp(tmp, color[i - 4], 2))
		return (ft_printf("Error\nProbleme de configuration des couleurs\n"),
			free(tmp), false);
	init_color(tmp, map_color[i - 4]);
	free(tmp);
	return (true);
}

static bool	check_texture(char	*tmp, int i) {
	const char	*dir[4] = {"NO ", "SO ", "WE ", "EA "};
	if (ft_strncmp(tmp, dir[i], 3))
		return (ft_printf("Error\nProbleme de configuration des textures\n"),
			free(tmp), false);
	free(tmp);
	return (true);
}

bool	parsing(int ac, char **av)
{
	int		i;
	int		fd;
	char	*tmp;
	bool	check;
	t_map	map;

	i = 0;
	if (ac != 2)
		return (false);
	if (!check_extension(av[1]))
		return (ft_printf("Error\nLe fichier n'est pas au bon format (.cub)\n"),
			false);
	fd = open(av[1], O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		ft_printf("%s", tmp);
		if (tmp_length(ft_strtrim(tmp, " ")) > 0 || i > 5)
		{
			if (i < 4)
				check = check_texture(ft_strtrim(tmp, " "), i);
			else if (i < 6)
				check = check_colors(ft_strtrim(tmp, " "), i, &map);
			else
				check = check_map(tmp);
			if (!check)
				return (free(tmp), false);
			i++;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	return (true);
}
