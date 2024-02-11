/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:35 by robhak            #+#    #+#             */
/*   Updated: 2023/04/28 17:39:19 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_calloc
** Paramètre(s): size_t nmemb, size_t size
** Valeur de retour: void *
** Description: Cette fonction alloue de la mémoire pour 
	un tableau de nmemb éléments de taille size octets chacun.
** Elle utilise la fonction malloc pour effectuer cette allocation.
** Elle remplit ensuite la zone mémoire allouée avec 
	des zéros en utilisant la fonction ft_memset.
** Si nmemb ou size est nul, la fonction alloue une zone mémoire de taille 0.
** Si l'allocation échoue ou si le produit de nmemb et 
	size dépasse la limite maximale, la fonction renvoie NULL.
** Exemple(s):
** int *tab = ft_calloc(5, sizeof(int)); -> tab = [0, 0, 0, 0, 0]
** char *str = ft_calloc(10, sizeof(char)); -> str = "\0\0\0\0\0\0\0\0\0\0"
** double *d = ft_calloc(0, sizeof(double)); -> d = NULL
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	total_size;

	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
		return (NULL);
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, total_size);
	return (memory);
}
