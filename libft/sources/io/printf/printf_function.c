/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:26:43 by robhak            #+#    #+#             */
/*   Updated: 2023/05/27 12:23:56 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * ft_putchar - Écrit un caractère sur la sortie standard.
 * @c: Le caractère à écrire.
 *
 * Retourne: Le nombre de caractères écrits (toujours 1).
 */
size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/*
 * ft_putstr - Écrit une chaîne de caractères sur la sortie standard.
 * @str: La chaîne de caractères à écrire.
 *
 * Retourne: Le nombre de caractères écrits.
 */
size_t	ft_putstr(char *str)
{
	size_t	i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str[i])
		cpt += ft_putchar(str[i++]);
	return (cpt);
}

/*
 * ft_putnbr - Écrit un entier sur la sortie standard.
 * @n: L'entier à écrire.
 *
 * Retourne: Le nombre de caractères écrits.
 */
size_t	ft_putnbr(int n)
{
	long long int	nbr;
	int				cpt;

	cpt = 0;
	nbr = (long long int)n;
	if (nbr < 0)
	{
		nbr = -nbr;
		write (1, "-", 1);
		cpt++;
	}
	if (nbr && nbr > 9)
		cpt += ft_putnbr(nbr / 10);
	cpt += ft_putchar (nbr % 10 + '0');
	return (cpt);
}

/*
 * ft_unsigned_nbr - Écrit un entier non signé sur la sortie standard.
 * @n: L'entier non signé à écrire.
 *
 * Retourne: Le nombre de caractères écrits.
 */
size_t	ft_unsigned_nbr(unsigned long long int n)
{
	int	cpt;

	cpt = 0;
	if (n && n > 9)
		cpt += ft_putnbr(n / 10);
	cpt += ft_putchar (n % 10 + '0');
	return (cpt);
}

/*
 * ft_putnbr_base - Écrit un entier non signé en base 16 sur la sortie standard.
 * @n: L'entier non signé à écrire.
 * @base: La chaîne de caractères représentant les chiffres de la base.
 *
 * Retourne: Le nombre de caractères écrits.
 */
size_t	ft_putnbr_base(unsigned long long int n, char *base)
{
	int	cpt;

	cpt = 0;
	if (n >= 16)
	{
		cpt += ft_putnbr_base(n / 16, base);
		cpt += ft_putchar(base[n % 16]);
	}
	else
		cpt += ft_putchar(base[n]);
	return (cpt);
}
