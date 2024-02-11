/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:15 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:32:40 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strncmp
** Paramètre(s): const char *s1, const char *s2, size_t n
** Valeur de retour: int
** Description: Cette fonction compare les n premiers caractères 
	des deux chaînes s1 et s2.
** Elle prend en paramètre les deux chaînes à comparer et 
	le nombre de caractères à comparer.
** Elle renvoie un entier négatif, nul ou positif si 
	s1 est respectivement inférieure, égale ou supérieure à s2.
** Elle utilise le code ASCII pour comparer les caractères.
** Exemple(s):
** ft_strncmp("Hello", "Hello world!", 5); 
	// renvoie 0 car les 5 premiers caractères sont identiques
** ft_strncmp("Hello", "Hello world!", 6); 
	// renvoie -32 car le 6ème caractère de s1 est '\0' et celui de s2 est ' '
** ft_strncmp("Hello", "hello", 3); 
	// renvoie -32 car le 3ème caractère de s1 est 'L' et celui de s2 est 'l'
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
