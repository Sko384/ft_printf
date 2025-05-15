/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 12:58:04 by shmiyosh          #+#    #+#             */
/*   Updated: 2025-05-11 12:58:04 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr *= -1;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	nbr = nbr % 10 + '0';
	write(1, &nbr, 1);
	count++;
	return (count);
}

int	ft_print_d(va_list args)
{
	int	num;
	int	count;

	num = va_arg(args, int);
	count = ft_putnbr(num);
	return (count);
}
