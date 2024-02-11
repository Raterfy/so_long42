/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:13 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 20:34:20 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Nom de la fonction: ft_memmove
** Paramètre(s): void *dest, const void *src, size_t n
** Valeur de retour: void *
** Description: Cette fonction copie une zone mémoire dans une autre en tenant 
	compte du chevauchement éventuel des zones.
** Elle prend en paramètre un pointeur sur la zone mémoire de destination, 
	un pointeur sur la zone mémoire source et le nombre d'octets à copier.
** Elle renvoie un pointeur sur la zone mémoire de destination.
** Exemple(s):
** char dest[] = "Hello world";
** ft_memmove(dest + 6, dest + 5, 6); // décale "world" 
	d'un caractère vers la droite
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = n;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
		while (i--)
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	return (dest);
}
