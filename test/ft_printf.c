/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-07 09:38:22 by shmiyosh          #+#    #+#             */
/*   Updated: 2025-05-07 09:38:22 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list args)
{
	int		val;
	char	c;

	val = va_arg(args, int);
	c = (char)val;
	write(1, &c, 1);
	return (1);
}

// int	ft_print_s(va_list args)
// {
// }

int	ft_conversions(const char c, va_list args)
{
	if (c == 'c' || c == '%')
		return (ft_print_c(args));
	return (ft_print_c(args));
	// else if (c == 's')
	// 	return (ft_print_s(args));
	// else if (c == 'p')
	// 	return (ft_print_p(args));
	// else if (c == 'd' || c == 'i')
	// 	return (ft_print_d(args));
	// else if (c == 'u')
	// 	return (ft_print_u(args));
	// else if (c == 'x' || c == 'X')
	// 	return (ft_print_x(args));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
		}
		count += ft_conversions(format[++i], args);
		if (!(ft_conversions(format[++i], args)))
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (i + count);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("abcde%c", 'F');
	// printf("abcde%c\n", 'F');
	return (0);
}
