/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:06 by robhak            #+#    #+#             */
/*   Updated: 2023/05/08 09:28:03 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_memcpy
** Paramètre(s): void *dest, const void *src, size_t n
** Valeur de retour: void *
** Description: Cette fonction copie une zone mémoire dans une autre.
** Elle prend en paramètre un pointeur sur la zone mémoire de destination, 
	un pointeur sur la zone mémoire source et le nombre d'octets à copier.
** Elle renvoie un pointeur sur la zone mémoire de destination.
** Exemple(s):
** char dest[10];
** char src[] = "Hello";
** ft_memcpy(dest, src, 6); // copie "Hello" et le caractère nul dans dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	if (!dest)
		return (NULL);
	dest_cpy = dest;
	src_cpy = src;
	while (n-- > 0)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
