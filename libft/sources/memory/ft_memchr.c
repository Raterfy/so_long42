/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:56 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:10:02 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_memchr
** Paramètre(s): const void *s, int c, size_t n
** Valeur de retour: void *
** Description: Cette fonction recherche un caractère dans une zone mémoire.
** Elle prend en paramètre un pointeur sur la zone mémoire, le caractère 
	à chercher et le nombre d'octets à examiner.
** Elle renvoie un pointeur sur la première occurrence du caractère 
	dans la zone mémoire, ou NULL si le caractère n'est pas trouvé.
** Exemple(s):
** char s[] = "Hello world";
** ft_memchr(s, 'w', 11); // renvoie un pointeur sur "world"
** ft_memchr(s, 'z', 11); // renvoie NULL
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		unsignedchar;

	unsignedchar = (unsigned char) c;
	p = s;
	while (n-- > 0)
	{
		if (*p == unsignedchar)
			return ((void *) p);
		p++;
	}
	return (NULL);
}
