/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:52:12 by shmiyosh          #+#    #+#             */
/*   Updated: 2025-05-12 14:52:12 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunbr(unsigned int nbr)
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

int	ft_print_u(va_list args)
{
	int				count;
	unsigned int	ul;

	count = 1;
	ul = va_arg(args, unsigned int);
	count = ft_putunbr(ul);
	return (count);
}
