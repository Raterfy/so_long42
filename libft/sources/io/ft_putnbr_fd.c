/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:06:50 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:33:06 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_putnbr_fd
** Paramètre(s): int n, int fd
** Valeur de retour: void
** Description: Cette fonction écrit un nombre entier sur un descripteur 
	de fichier.
** Elle prend en paramètre le nombre à écrire et le descripteur 
	de fichier sur lequel écrire.
** Elle utilise les fonctions write et ft_putchar_fd pour écrire le nombre.
** Elle gère les nombres négatifs en écrivant un signe moins devant le nombre.
** Elle utilise la récursivité pour écrire le nombre chiffre par chiffre.
** Exemple(s):
** ft_putnbr_fd(42, 1); // écrit "42" sur la sortie standard
** ft_putnbr_fd(-123, 2); // écrit "-123" sur la sortie d'erreur
*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr != 0 && nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr = nbr % 10 + '0', fd);
}
