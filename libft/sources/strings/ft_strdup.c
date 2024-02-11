/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:58 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:04:55 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strdup
** Paramètre(s): const char *s
** Valeur de retour: char *
** Description: Cette fonction alloue de la mémoire et copie la chaîne s 
	dans cette mémoire.
** Elle prend en paramètre la chaîne à dupliquer.
** Elle renvoie un pointeur sur la nouvelle chaîne, 
	ou NULL si l'allocation échoue.
** Elle utilise les fonctions malloc, ft_strlen et ft_memcpy pour allouer, 
	calculer la longueur et copier la chaîne.
** Exemple(s):
** ft_strdup("Hello"); // renvoie un pointeur sur une nouvelle chaîne "Hello"
** ft_strdup(""); // renvoie un pointeur sur une nouvelle chaîne ""
** ft_strdup(NULL); // comportement indéfini
*/
char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s) + 1;
	new_str = malloc(len);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s, len);
	return (new_str);
}
