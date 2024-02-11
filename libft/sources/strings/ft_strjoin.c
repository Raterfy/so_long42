/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:02 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:13:21 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strjoin
** Paramètre(s): char const *s1, char const *s2
** Valeur de retour: char *
** Description: Cette fonction alloue de la mémoire et concatène 
	les deux chaînes s1 et s2 dans cette mémoire.
** Elle prend en paramètre les deux chaînes à joindre.
** Elle renvoie un pointeur sur la nouvelle chaîne, ou NULL si 
	l'une des chaînes est nulle ou si l'allocation échoue.
** Elle utilise les fonctions malloc, ft_strlen et ft_memcpy pour allouer, 
	calculer la longueur et copier les chaînes.
** Exemple(s):
** ft_strjoin("Hello", " world!"); 
	// renvoie un pointeur sur une nouvelle chaîne "Hello world!"
** ft_strjoin("Bonjour", ""); 
	// renvoie un pointeur sur une nouvelle chaîne "Bonjour"
** ft_strjoin(NULL, "Hello"); // renvoie NULL
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, s2_len);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}
