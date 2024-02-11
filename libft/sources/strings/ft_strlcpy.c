/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:09 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:18:35 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strlcpy
** Paramètre(s): char *dst, const char *src, size_t size
** Valeur de retour: size_t
** Description: Cette fonction copie au plus size - 1 caractères 
	de la chaîne src dans la chaîne dst, en terminant par un caractère nul.
** Elle prend en paramètre la chaîne de destination, la chaîne source 
	et la taille du buffer de destination.
** Elle renvoie la longueur de la chaîne source.
** Elle utilise les fonctions ft_strlen et ft_memcpy pour calculer 
	la longueur et copier les caractères.
** Exemple(s):
** char dst[10];
** ft_strlcpy(dst, "Hello", 10); // renvoie 5 et dst vaut "Hello"
** char dst[10];
** ft_strlcpy(dst, "Hello world!", 10); // renvoie 12 et dst vaut "Hello worl"
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if (size > 0)
	{
		dstlen = size - 1;
		if (srclen < dstlen)
			ft_memcpy(dst, src, srclen + 1);
		else
		{
			ft_memcpy(dst, src, dstlen);
			dst[dstlen] = '\0';
		}
	}
	return (srclen);
}
