/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:19 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:36:33 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strnstr
** Paramètre(s): const char *big, const char *little, size_t len
** Valeur de retour: char *
** Description: Cette fonction recherche la première occurrence de 
	la chaîne little dans la chaîne big, en considérant 
	seulement les len premiers caractères de big.
** Elle prend en paramètre la chaîne où chercher, la chaîne à 
	chercher et le nombre de caractères à considérer.
** Elle renvoie un pointeur sur le début de l'occurrence trouvée, 
	ou NULL si aucune occurrence n'est trouvée ou si len est nul.
** Elle renvoie un pointeur sur big si little est vide.
** Elle utilise les fonctions ft_strlen et ft_memcmp pour calculer 
	la longueur et comparer les chaînes.
** Exemple(s):
** ft_strnstr("Hello world!", "world", 10); 
	// renvoie NULL car on ne considère que les 10 premiers 
	// caractères de "Hello world!"
** ft_strnstr("Hello world!", "world", 11); 
	// renvoie un pointeur sur "world!"
** ft_strnstr("Hello world!", "Hello", 5); 
	// renvoie un pointeur sur "Hello world!"
** ft_strnstr("Hello world!", "", 5); 
	// renvoie un pointeur sur "Hello world!"
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(little);
	if (needle_len == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (*big && len-- >= needle_len)
	{
		if (*big == *little
			&& ft_memcmp(big, little, needle_len) == 0)
			return ((char *) big);
		big++;
	}
	return (NULL);
}
