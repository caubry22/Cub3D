/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:12:04 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 16:12:05 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	__treat_format(t_struct *content, va_list argument)
{
	if (content->conversion == 'd' || content->conversion == 'i')
		__putnbr(va_arg(argument, int), content);
	else if (content->conversion == 'c')
		__putchar(va_arg(argument, int), content);
	else if (content->conversion == 's')
		__putstr(va_arg(argument, char *), content);
	else if (content->conversion == 'p')
		__print_memory(va_arg(argument, void *), content);
	else if (content->conversion == 'x')
		__base((unsigned long long)va_arg(argument, unsigned int), M, content);
	else if (content->conversion == 'u')
		__base((unsigned long long)va_arg(argument, unsigned int), D, content);
	else if (content->conversion == 'X')
		__base((unsigned long long)va_arg(argument, unsigned int), R, content);
	else if (content->conversion == '%')
		__putchar('%', content);
	else
		return ;
}

int	ft_printf(const char *format_str, ...)
{
	va_list		arguments;
	t_struct	content;
	int			i;

	content.ret = 0;
	i = 0;
	va_start(arguments, format_str);
	while (format_str[i])
	{
		if (format_str[i] == '%')
		{
			content.conversion = format_str[i + 1];
			__treat_format(&content, arguments);
			i++;
		}
		else
			__putchar(format_str[i], &content);
		i++;
	}
	va_end(arguments);
	return (content.ret);
}