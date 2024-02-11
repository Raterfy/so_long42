/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:17 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:25:30 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_memset
** Paramètre(s): void *s, int c, size_t n
** Valeur de retour: void *
** Description: Cette fonction remplit une zone mémoire avec un caractère donné.
** Elle prend en paramètre un pointeur sur la zone mémoire à remplir, 
	le caractère à utiliser et le nombre d'octets à remplir.
** Elle renvoie un pointeur sur la zone mémoire remplie.
** Exemple(s):
** char s[10];
** ft_memset(s, 'a', 10); // remplit s avec 10 'a'
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) s;
	while (n-- > 0)
		*p++ = c;
	return (s);
}
