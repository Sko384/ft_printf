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
#include <stdio.h>

static int	ft_print_c(va_list args)
{
	int				val;
	unsigned char	c;

	val = va_arg(args, int);
	c = (char)val;
	return (write(1, &c, 1));
}

static int	ft_print_per(char per)
{
	return (write(1, &per, 1));
}

static int	ft_print_s(va_list args)
{
	char	*val;
	int		count;

	count = 0;
	val = va_arg(args, char *);
	if (!val)
		return (write(1, "(null)", 6));
	while (val[count])
	{
		write(1, &val[count], 1);
		count++;
	}
	return (count);
}

static int	ft_conversions(const char c, va_list args)
{
	int	word_count;

	word_count = 0;
	if (c == 'c')
		word_count = (ft_print_c(args));
	else if (c == '%')
		word_count = (ft_print_per('%'));
	else if (c == 's')
		word_count = (ft_print_s(args));
	else if (c == 'p')
		word_count = (ft_print_p(args));
	else if (c == 'd' || c == 'i')
		word_count = (ft_print_d(args));
	else if (c == 'u')
		word_count = (ft_print_u(args));
	else if (c == 'x')
		word_count = (ft_print_x(args, c, "0123456789abcdef", 16));
	else if (c == 'X')
		word_count = (ft_print_x(args, c, "0123456789ABCDEF", 16));
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
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			count += ft_conversions(format[++i], args);
			i++;
		}
	}
	va_end(args);
	return (count);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int				count;
// 	int				count_t;
// 	int				d;
// 	unsigned int	ui;
// 	char			c[] = "wow wow";

// 	d = 12345;
// 	ui = -1;
// 	// ft_printf("abcde%c%s%p %d %i\n", 'F', "what?\n", c, -0, 12345);
// 	count = ft_printf(" %c %c %c \n", '0', 0, '1');
// 	count_t = printf(" %c %c %c \n", '0', 0, '1');
// 	printf("\n文字数：%d\n", count);
// 	printf("文字数：%d\n", count_t);
// 	// ft_printf("%c\n", '0');
// 	// printf("%c\n", '0');
// 	return (0);
// }

// void	print_section(const char *title)
// {
// 	printf("\n========== %s ==========\n", title);
// }

// int	main(void)
// {
// 	char			*str;
// 	void			*ptr;
// 	unsigned int	u;
// 	unsigned int	overflow_uint;
// 	unsigned int	underflow_uint;
// 	int				n;
// 	char			c;
// 	int				overflow_int;
// 	int				underflow_int;

// 	n = -42;
// 	str = "Banana";
// 	c = 'B';
// 	ptr = str;
// 	u = 1234567890U;
// 	// ======== 通常動作チェック =========
// 	print_section("NORMAL CASES");
// 	ft_printf("test_printf: %%d => %d\n", n);
// 	printf("printf:    %%d => %d\n\n", n);
// 	ft_printf("test_printf: %%u => %u\n", u);
// 	printf("printf:    %%u => %u\n\n", u);
// 	ft_printf("test_printf: %%x => %x\n", n);
// 	printf("printf:    %%x => %x\n\n", n);
// 	ft_printf("test_printf: %%X => %X\n", n);
// 	printf("printf:    %%X => %X\n\n", n);
// 	ft_printf("test_printf: %%p => %p\n", ptr);
// 	printf("printf:    %%p => %p\n\n", ptr);
// 	ft_printf("test_printf: %%s => %s\n", str);
// 	printf("printf:    %%s => %s\n\n", str);
// 	ft_printf("test_printf: %%c => %c\n", c);
// 	printf("printf:    %%c => %c\n\n", c);
// 	ft_printf("test_printf: %% percent => %%\n");
// 	printf("printf:    %% percent => %%\n");
// 	// ======== 極端なケースチェック =========
// 	print_section("EDGE CASES (Overflow / Underflow)");
// 	overflow_int = INT_MAX + 1;
// 	underflow_int = INT_MIN - 1;
// 	overflow_uint = UINT_MAX + 1U;
// 	underflow_uint = 0 - 1U;
// 	ft_printf("test_printf: INT_MAX       => %d\n", INT_MAX);
// 	printf("printf:    INT_MAX       => %d\n\n", INT_MAX);
// 	ft_printf("test_printf: INT_MIN       => %d\n", INT_MIN);
// 	printf("printf:    INT_MIN       => %d\n\n", INT_MIN);
// 	ft_printf("test_printf: INT OVERFLOW  => %d\n", overflow_int);
// 	printf("printf:    INT OVERFLOW  => %d\n\n", overflow_int);
// 	ft_printf("test_printf: INT UNDERFLOW => %d\n", underflow_int);
// 	printf("printf:    INT UNDERFLOW => %d\n\n", underflow_int);
// 	ft_printf("test_printf: UINT_MAX      => %u\n", UINT_MAX);
// 	printf("printf:    UINT_MAX      => %u\n\n", UINT_MAX);
// 	ft_printf("test_printf: UINT OVERFLOW => %u\n", overflow_uint);
// 	printf("printf:    UINT OVERFLOW => %u\n\n", overflow_uint);
// 	ft_printf("test_printf: UINT UNDERFLOW=> %u\n", underflow_uint);
// 	printf("printf:    UINT UNDERFLOW=> %u\n\n", underflow_uint);
// 	return (0);
// }
