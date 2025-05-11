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

int	ft_print_p(va_list args)
{
	int				count;
	void			*array;
	unsigned char	*c;

	count = 0;
	array = va_arg(args, void *);
	c = array;
	while (c[count])
	{
		write(1, &c[count], 1);
		count++;
	}
	return (count);
}
