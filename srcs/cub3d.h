/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:39:07 by odessein          #+#    #+#             */
/*   Updated: 2022/11/29 18:30:44 by caubry           ###   ########.fr       */
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

typedef struct s_struct
{
	char	conversion;
	int		ret;

}	t_struct;

typedef struct s_map
{
	int size[2];
	char **init_map;
	int	color_floor[4];
	int	color_ceiling[4];
	char *texture[5];
}	t_map;

//   ---     MAIN     ---

void		init_map(t_map *map);


//   ---     PARSING     ---

// parsing.c

bool		check_extension(char *map);
bool		check_map(char *tmp, t_map *map);
bool		parsing_loop(char *tmp, int *i, t_map *map);
bool		parsing(int ac, char **av, t_map *map);
void		print_map(t_map *map);


// check_texture_color.c

bool		init_color(char *tmp, int *color);
bool		check_colors(char *tmp, t_map *map);
bool		init_textures(char *tmp, int i, t_map *map);
bool		check_texture(char	*tmp, t_map *map);
int			is_texture_or_color(char *tmp);


// parsing_utils.c

int			tmp_length(char	*tmp);
int			line_map_length(char *tmp);


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





#endif
