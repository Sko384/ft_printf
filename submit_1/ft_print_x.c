/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 21:27:41 by shmiyosh          #+#    #+#             */
/*   Updated: 2025-05-12 21:27:41 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count = ft_putunbr(nbr / 10);
	nbr = nbr % 10 + '0';
	write(1, &nbr, 1);
	count++;
	return (count);
}

int	ft_print_x(va_list args)
{
	unsigned int	nbr;
	int				count;

	nbr = va_arg(args, unsigned int);
	count = ft_putnbr_base(nbr);
	return (count);
}
