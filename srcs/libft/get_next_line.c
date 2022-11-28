#include "../../cub3d.h"

size_t	__strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*__strdup(const char *s1)
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final_line;

	i = 0;
	j = 0;
	if (!s1)
		s1 = __strdup("");
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

int	_is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

char	*_get_line(char *str)
{
	int		i;
	char	*final_str;

	i = 0;
	if (!str)
		return (NULL);
	final_str = (char *)malloc(sizeof(char) * (__strlen(str) + 1));
	if (!(final_str))
		return (0);
	while (str[i])
	{
		final_str[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	final_str[i] = 0;
	return (final_str);
}

int	_is_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (_is_newline(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*_get_save(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && !_is_newline(save[i]))
		i++;
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	if (save[i])
		i++;
	new_save = (char *)malloc(sizeof(char) * (__strlen(save + i) + 1));
	if (!new_save)
		return (0);
	while (save[i])
	{
		new_save[j] = save[i];
		i++;
		j++;
	}
	new_save[j] = 0;
	return (free(save), new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[5 + 1];
	char		*line;
	int			ret;

	if (fd < 0)
		return (0);
	if (fd == -1 && save)
	{
		free(save);
		save = NULL;
	}
	ret = 1;
	while (ret && !_is_line(save))
	{
		ret = read(fd, buffer, 5);
		if (ret <= 0)
			break ;
		buffer[ret] = '\0';
		save = ft_strjoin(save, buffer);
	}
	line = _get_line(save);
	save = _get_save(save);
	return (line);
}
