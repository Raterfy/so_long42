/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:45:42 by robhak            #+#    #+#             */
/*   Updated: 2023/06/01 12:24:47 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * print_format2 - Appelle la fonction d'impression appropriée 
 * en fonction du caractère  de format spécifié.
 * @format: Le caractère de format spécifiant le type d'argument à imprimer.
 * @args: La liste d'arguments contenant l'argument à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
size_t	print_format(const char format, va_list args)
{
	if (format == 'c')
		return (print_c(args));
	else if (format == 's')
		return (print_s(args));
	else if (format == 'p')
		return (print_p(args));
	else if (format == 'd' || format == 'i')
		return (print_d_and_i(args));
	else if (format == 'u')
		return (print_u(args));
	else if (format == 'x')
		return (print_x(args));
	else if (format == 'X')
		return (print_upper_x(args));
	else if (format == '%')
		return (print_percent());
	return (0);
}

/*
 * ft_printf - Imprime des arguments formatés à l'écran.
 * @format: La chaîne de format spécifiant les types d'arguments à imprimer.
 * @...: Les arguments à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
int	ft_printf(const char *format, ...)
{
	int		cpt;
	int		i;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	cpt = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			cpt += print_format(format[i], args);
		}
		else
			cpt += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (cpt);
}
