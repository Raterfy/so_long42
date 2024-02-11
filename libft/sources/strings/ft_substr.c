/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:35 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:45:33 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_substr
** Paramètre(s): char const *s, unsigned int start, size_t len
** Valeur de retour: char *
** Description: Cette fonction alloue de la mémoire 
	et renvoie une sous-chaîne de la chaîne s. 
** La sous-chaîne commence à l’index start et a pour taille maximale len.
** Elle prend en paramètre la chaîne dont on veut extraire la sous-chaîne, 
	l'index de départ et la taille maximale de la sous-chaîne.
** Elle renvoie un pointeur sur la sous-chaîne, ou NULL si la chaîne 
	est nulle ou si l'allocation échoue.
** Elle renvoie une chaîne vide si start est supérieur à la longueur de s.
** Elle utilise les fonctions malloc, ft_strlen et ft_strdup pour allouer, 
	calculer la longueur et copier la chaîne.
** Exemple(s):
** ft_substr("Hello world!", 6, 5); 
	// renvoie un pointeur sur une nouvelle chaîne "world"
** ft_substr("Hello world!", 0, 5); 
	// renvoie un pointeur sur une nouvelle chaîne "Hello"
** ft_substr("Hello world!", 12, 5); 
	// renvoie un pointeur sur une nouvelle chaîne ""
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
