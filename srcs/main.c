#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_printf("Error\nIl faut mettre en argument le fichier de description de scene\n"), 1);
	if (!parsing(ac, av, &map))
		return (1);
	return (1);
}
