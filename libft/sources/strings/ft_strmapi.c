/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:56:37 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:28:43 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strmapi
** Paramètre(s): char const *s, char (*f)(unsigned int, char)
** Valeur de retour: char *
** Description: Cette fonction applique la fonction f à chaque caractère de 
	la chaîne s en passant son index en premier argument et crée 
	une nouvelle chaîne avec les résultats.
** Elle prend en paramètre la chaîne à parcourir et la fonction à appliquer.
** Elle renvoie un pointeur sur la nouvelle chaîne, ou NULL si la chaîne 
	est nulle ou si l'allocation échoue.
** Elle utilise les fonctions malloc pour allouer la mémoire.
** Exemple(s):
** char ft_toupper(unsigned int i, char c)
** {
**     if (c >= 'a' && c <= 'z')
**         return (c - 32);
**     else
**         return (c);
** }
**
** ft_strmapi("Hello", ft_toupper); 
	// renvoie un pointeur sur une nouvelle chaîne "HELLO"
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
