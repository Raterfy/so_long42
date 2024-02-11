/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:27 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:39:59 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strrchr
** Paramètre(s): const char *s, int c
** Valeur de retour: char *
** Description: Cette fonction recherche la dernière occurrence du caractère 
	c dans la chaîne s.
** Elle prend en paramètre la chaîne à parcourir et le caractère à chercher.
** Elle renvoie un pointeur sur le caractère trouvé, ou NULL si le caractère 
	n'est pas présent dans la chaîne.
** Elle gère le cas particulier où c est le caractère nul '\0'.
** Exemple(s):
** ft_strrchr("Hello", 'l'); // renvoie un pointeur sur "lo"
** ft_strrchr("Hello", 'z'); // renvoie NULL
** ft_strrchr("Hello", '\0'); // renvoie un pointeur sur ""
*/
char	*ft_strrchr(const char *s, int c)
{
	const char		*p;
	unsigned char	character;

	character = c;
	if (character == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	p = NULL;
	while (*s)
	{
		if (*s == character)
			p = s;
		s++;
	}
	return ((char *)p);
}
