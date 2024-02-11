/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:26:39 by robhak            #+#    #+#             */
/*   Updated: 2023/10/10 21:34:44 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
size_t	ft_putnbr(int n);
size_t	ft_unsigned_nbr(unsigned long long int n);
size_t	ft_putnbr_base(unsigned long long int n, char *base);
size_t	print_c(va_list args);
size_t	print_s(va_list args);
size_t	print_p(va_list args);
size_t	print_d_and_i(va_list args);
size_t	print_u(va_list args);
size_t	print_x(va_list args);
size_t	print_upper_x(va_list args);
size_t	print_percent(void);
size_t	print_format(const char format, va_list args);
int		ft_printf(const char *format, ...);

#endif