/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-07 11:13:24 by shmiyosh          #+#    #+#             */
/*   Updated: 2025-05-07 11:13:24 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *, ...);
int	ft_print_p(va_list args);
int	ft_print_d(va_list args);
int	ft_print_u(va_list args);
int	ft_print_x(va_list args);

#endif
