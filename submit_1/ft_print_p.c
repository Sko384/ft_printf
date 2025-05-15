/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-08 16:32:32 by shmiyosh          #+#    #+#             */
/*   Updated: 2025-05-08 16:32:32 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_putptr(uintptr_t ptr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_putptr(ptr / 16);
	write(1, &hex[ptr % 16], 1);
	return (count + 1);
}

int	ft_print_p(va_list args)
{
	int			count;
	void		*array;
	uintptr_t	c;

	count = 0;
	array = va_arg(args, void *);
	c = (uintptr_t)array;
	count += write(1, "0x", 2);
	count += ft_putptr(c);
	return (count);
}
