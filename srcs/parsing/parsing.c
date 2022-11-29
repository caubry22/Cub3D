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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static bool	init_color(char *tmp, int *color)
{
	int	i;
	int	j;
	int	rgb;
	int	comma;

	i = 2;
	comma = 0;
	while (tmp[i] && tmp[i] == ' ')
		i++;
	while(tmp[i])
	{
		rgb = 0;
		j = 0;
		while (tmp[i + j] && ft_isdigit(tmp[i + j]))
		{
			rgb = rgb * 10 + tmp[i + j] - '0';
			j++;
		}
		if (rgb > 255 || !j)
			return (false);
		else
			color[comma] = rgb;
		i += j + 1;
		comma++;
	}
	if (comma != 3)
		return (false);
	return (true);
}

static bool	check_colors(char *tmp, int i, t_map *map)
{
	const char	*color[2] = {"F ", "C "};
	int			*map_color[2] = {map->color_floor, map->color_ceiling};
	if (ft_strncmp(tmp, color[i - 4], 2))
		return (ft_printf("Error\nProbleme de configuration des couleurs\n"),
			free(tmp), false);
	if (!init_color(tmp, map_color[i - 4]))
		return (ft_printf("Error\nProbleme de configuration des couleurs\n"), false);
	free(tmp);
	return (true);
}

static bool	init_textures(char *tmp, int i, t_map *map)
{
	int j;
	int fd;

	j = 2;
	while (tmp[j] && tmp[j] == ' ')
		j++;
	map->texture[i] = ft_strtrim(ft_strdup(tmp + j), "\n");
	fd = open(map->texture[i], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		perror(map->texture[i]);
		free(map->texture[i]);
		return (false);
	}
	close(fd);
	return (true);
}

static bool	check_texture(char	*tmp, int i, t_map *map) {
	const char	*dir[4] = {"NO ", "SO ", "WE ", "EA "};
	if (ft_strncmp(tmp, dir[i], 3))
		return (ft_printf("Error\nProbleme de configuration des textures\n"),
			free(tmp), false);
	if (!init_textures(tmp, i, map))
		return (false);
	free(tmp);
	return (true);
}

bool	parsing(int ac, char **av, t_map *map)
{
	int		i;
	int		fd;
	char	*tmp;
	bool	check;

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
		if (tmp_length(ft_strtrim(tmp, " ")) > 0 || i > 5)
		{
			if (i < 4)
				check = check_texture(ft_strtrim(tmp, " "), i, map);
			else if (i < 6)
				check = check_colors(ft_strtrim(tmp, " "), i, map);
			else
				check = check_map(tmp);
			if (!check)
				return (free(tmp), false);
			i++;
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	ft_printf("north texture = %s\n", map->texture[0]);
	ft_printf("south texture = %s\n", map->texture[1]);
	ft_printf("west texture = %s\n", map->texture[2]);
	ft_printf("east texture = %s\n", map->texture[3]);
	ft_printf("color floor = %d,%d,%d\n", map->color_floor[0], map->color_floor[1], map->color_floor[2]);
	ft_printf("color ceiling = %d,%d,%d\n", map->color_ceiling[0], map->color_ceiling[1], map->color_ceiling[2]);
	free(tmp);
	return (true);
}
