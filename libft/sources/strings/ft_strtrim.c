/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:32 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:42:59 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strtrim
** Paramètre(s): char const *s1, char const *set
** Valeur de retour: char *
** Description: Cette fonction alloue de la mémoire et renvoie une copie 
	de la chaîne s1, sans les caractères spécifiés dans set au début 
	et à la fin de la chaîne.
** Elle prend en paramètre la chaîne à tronquer et l'ensemble 
	des caractères à supprimer.
** Elle renvoie un pointeur sur la nouvelle chaîne, ou NULL si 
	l'une des chaînes est nulle ou si l'allocation échoue.
** Elle utilise les fonctions ft_strlen, ft_strchr et ft_substr 
	pour calculer la longueur, chercher les caractères et 
	extraire la sous-chaîne.
** Exemple(s):
** ft_strtrim("  Hello world!  ", " "); 
	// renvoie un pointeur sur une nouvelle chaîne "Hello world!"
** ft_strtrim("Hello world!", "Hd!"); 
	// renvoie un pointeur sur une nouvelle chaîne "ello worl"
** ft_strtrim("Hello", ""); 
	// renvoie un pointeur sur une nouvelle chaîne "Hello"
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}
