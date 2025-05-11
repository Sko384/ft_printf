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

int	ft_print_s(va_list args)
{
	char	*val;
	int		count;

	count = 0;
	val = va_arg(args, char *);
	while (val[count])
	{
		write(1, &val[count], 1);
		count++;
	}
	return (count);
}

int	ft_conversions(const char c, va_list args)
{
	int	word_count;

	word_count = 0;
	if (c == 'c' || c == '%')
		word_count = (ft_print_c(args));
	else if (c == 's')
		word_count = (ft_print_s(args));
	else if (c == 'p')
		word_count = (ft_print_p(args));
	else if (c == 'd' || c == 'i')
		word_count = (ft_print_d(args));
	// else if (c == 'u')
	// 	return (ft_print_u(args));
	// else if (c == 'x' || c == 'X')
	// 	return (ft_print_x(args));
	return (word_count);
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
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
		}
		else
		{
			if (format[i + 1])
				count = ft_conversions(format[++i], args);
			i++;
		}
	}
	va_end(args);
	return (i + count);
}

#include <stdio.h>

int	main(void)
{
	char c[] = "wow wow";
	ft_printf("abcde%c%s%p %d\n", 'F', "what?", c, 1234);
	ft_printf("abcde%c%s\n", 'F', "what?");
	// printf("abcde%c%\n", 'F', "what?");
	return (0);
}
