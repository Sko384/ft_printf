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

int	ft_putnbr_base(unsigned int nbr, const char c, char *base,
		unsigned int base_len)
{
	int		count;
	char	ch;

	count = 0;
	if (nbr >= base_len)
		count = ft_putnbr_base(nbr / base_len, c, base, base_len);
	nbr = nbr % base_len + '0';
	if (c == 'X')
		ch = base[nbr % base_len];
	else
		ch = base[nbr % base_len];
	write(1, &ch, 1);
	return (count + 1);
}

int	ft_print_x(va_list args, const char c, char *base, unsigned int base_len)
{
	unsigned int	nbr;
	int				count;

	nbr = va_arg(args, unsigned int);
	count = ft_putnbr_base(nbr, c, base, base_len);
	return (count);
}
