/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:02 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:14:09 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_memcmp
** Paramètre(s): const void *s1, const void *s2, size_t n
** Valeur de retour: int
** Description: Cette fonction compare deux zones mémoire.
** Elle prend en paramètre deux pointeurs sur les zones mémoire à comparer 
	et le nombre d'octets à examiner.
** Elle renvoie un entier négatif, nul ou positif selon que la première zone 
	est inférieure, égale ou supérieure à la seconde.
** Exemple(s):
** char s1[] = "Hello";
** char s2[] = "World";
** ft_memcmp(s1, s2, 5); // renvoie -15
** ft_memcmp(s1, s1, 5); // renvoie 0
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
