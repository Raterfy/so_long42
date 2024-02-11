/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:06:35 by robhak            #+#    #+#             */
/*   Updated: 2023/05/27 12:21:34 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * print_c - Imprime un caractère passé en argument.
 * @args: La liste d'arguments contenant le caractère à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés (toujours 1).
 */
size_t	print_c(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putchar(va_arg(args, int));
	return (cpt);
}

/*
 * print_s - Imprime une chaîne de caractères passée en argument.
 * @args: La liste d'arguments contenant la chaîne de caractères à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
size_t	print_s(va_list args)
{
	int		cpt;
	char	*str;

	cpt = 0;
	str = va_arg(args, char *);
	if (!str)
		cpt = ft_putstr("(null)");
	else
		cpt = ft_putstr(str);
	return (cpt);
}

/*
 * print_p - Imprime une adresse mémoire passée en argument.
 * @args: La liste d'arguments contenant l'adresse mémoire à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
size_t	print_p(va_list args)
{
	int		cpt;
	void	*ptr;

	cpt = 0;
	ptr = va_arg(args, void *);
	if (!ptr)
		cpt += ft_putstr("(nil)");
	else
	{
		cpt += ft_putstr("0x");
		cpt += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	}
	return (cpt);
}

/*
 * print_d_and_i - Imprime un entier signé passé en argument.
 * @args: La liste d'arguments contenant l'entier signé à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
size_t	print_d_and_i(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_putnbr(va_arg(args, int));
	return (cpt);
}

/*
 * print_u - Imprime un entier non signé passé en argument.
 * @args: La liste d'arguments contenant l'entier non signé à imprimer.
 *
 * Retourne: Le nombre de caractères imprimés.
 */
size_t	print_u(va_list args)
{
	int	cpt;

	cpt = 0;
	cpt += ft_unsigned_nbr(va_arg(args, unsigned int));
	return (cpt);
}
