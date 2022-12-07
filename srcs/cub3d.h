/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:52:41 by caubry            #+#    #+#             */
/*   Updated: 2022/12/02 15:21:55 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef M
#  define M "0123456789abcdef"
# endif

# ifndef D
#  define D "0123456789"
# endif

# ifndef R
#  define R "0123456789ABCDEF"
# endif

# define PI 3.1415926535

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <errno.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_struct
{
	char	conversion;
	int		ret;

}	t_struct;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	int size[2];
	char **init_map;
	int	color_floor[4];
	int	color_ceiling[4];
	char *texture[5];
	char player;
	int		player_pos[2]; 	//je rajoute ca pour pouvoir calculer la position en pixel du joueur
	float	angle;
}	t_map;

typedef struct s_player
{
	// a changer de place
	void	*mlx_id;
	void	*win;
	void	*img;
	int		*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	// 
	float		px;
	float		py;
	float		delx;
	float		dely;
	float		angle;
}	t_player;


//   ---     MAIN     ---

void		init_map(t_map *map);


//   ---     PARSING     ---

// parsing.c

bool		check_extension(char *map);
bool		check_map(char *tmp, t_map *map);
bool		parsing_loop(char *tmp, int *i, t_map *map);
bool		parsing(int ac, char **av, t_map *map);
void		print_map(t_map *map);


// check_texture.c

bool		init_textures(char *tmp, int i, t_map *map);
bool		check_texture(char	*tmp, t_map *map);
int			is_texture_or_color(char *tmp);


// check_color.c

bool		valid_color(char *tmp, int *ptr_i, int comma, int *color);
bool		init_color(char *tmp, int *color);
bool		check_colors(char *tmp, t_map *map);


// check_map_valid.c

void	fill_line(char *real_map, char *tab_map, int width);
void	create_map(t_map *map, int height, char *map_in_line);
bool	check_map(char *tmp, t_map *map);


// check_map_closed.c

bool	check_over_under(char *under_over, int y);
bool	check_side(char *empty, int y);
bool	inside_map(char **map, int x, t_map *config);
bool	map_is_closed(char **map, int height, t_map *config);


// parsing_utils.c

int			tmp_length(char	*tmp);
int			line_map_length(char *tmp);

//   ---     EXEC     ---

// player.c

int			init_player(t_player *data, t_map *map);
int			draw_player(t_player *data, int width, int color);
int			ft_kinput(int keysym, t_data *data);

//   ---     LIBFT     ---

// ft_printf.c

int			ft_printf(const char *format_str, ...);
void		__treat_format(t_struct *content, va_list argument);

// ft_printf_utils.c

void		__print_memory(void *nb, t_struct *content);
void		__putnbr(int n, t_struct *content);
void		__base(unsigned long long nb, char *base, t_struct *content);
void		__putstr(char *str, t_struct *content);
void		__putchar(char c, t_struct *content);

// get_next_line.c

int			_is_newline(char c);
char		*_get_line(char *str);
int			_is_line(char *str);
char		*_get_save(char *save);
char		*get_next_line(int fd);

// strtrim.c

int			__is_charset(char *sep, char c);
int			__calculate_str(char *str, char *sep);
char		*ft_strtrim(char const *s1, char const *set);

// split.c

char	**ft_split(char const *s, char c);

// Autres fonctions libft

int			ft_isdigit(int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
size_t		__strlen(const char *s);
char		*ft_strchr(const char *s, int c);




#endif
