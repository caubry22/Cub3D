/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:39:07 by odessein          #+#    #+#             */
/*   Updated: 2022/11/24 10:46:28 by odessein         ###   ########.fr       */
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

typedef struct s_struct
{
	char	conversion;
	int		ret;

}	t_struct;

typedef struct s_map
{
	int	width;
	int	height;
	int	*color_floor[3];
	int	*color_ceiling[3];
}	t_map;

bool	parsing(int ac, char **av);
bool	check_extension(char *map);
char	*get_next_line(int fd);
int		ft_stop(char *tmp);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_memmove(char *dst, char *src, int k);
int		ft_srcsize(char *content);
void	__print_memory(void *nb, t_struct *content);
void	__putnbr(int n, t_struct *content);
void	__base(unsigned long long nb, char *base, t_struct *content);
void	__putstr(char *str, t_struct *content);
void	__putchar(char c, t_struct *content);
int		ft_printf(const char *format_str, ...);
char	*ft_strtrim(char const *s1, char const *set);
size_t	__strlen(const char *s);
char	*__strdup(const char *s1);
int			tmp_length(char	*tmp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);



#endif
