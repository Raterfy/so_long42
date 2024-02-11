/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:52 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:02:11 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strchr
** Paramètre(s): const char *s, int c
** Valeur de retour: char *
** Description: Cette fonction recherche la première occurrence 
	du caractère c dans la chaîne s.
** Elle prend en paramètre la chaîne à parcourir et le caractère à chercher.
** Elle renvoie un pointeur sur le caractère trouvé, ou NULL si 
	le caractère n'est pas présent dans la chaîne.
** Elle gère le cas particulier où c est le caractère nul '\0'.
** Exemple(s):
** ft_strchr("Hello", 'e'); // renvoie un pointeur sur "ello"
** ft_strchr("Hello", 'z'); // renvoie NULL
** ft_strchr("Hello", '\0'); // renvoie un pointeur sur ""
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	character = c;
	while (*s)
	{
		if (*s == character)
			return ((char *)s);
		++s;
	}
	if (character == '\0')
		return ((char *)s);
	return (NULL);
}
