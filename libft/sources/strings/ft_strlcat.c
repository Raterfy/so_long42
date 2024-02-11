/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:05 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:15:44 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strlcat
** Paramètre(s): char *dst, const char *src, size_t size
** Valeur de retour: size_t
** Description: Cette fonction copie au plus size - 1 caractères de la chaîne 
	src à la fin de la chaîne dst, en terminant par un caractère nul.
** Elle prend en paramètre la chaîne de destination, la chaîne source 
	et la taille du buffer de destination.
** Elle renvoie la longueur totale de la chaîne qu'elle a essayé de créer, 
	c'est-à-dire la longueur initiale de dst plus la longueur de src.
** Elle renvoie 0 si l'une des chaînes est nulle.
** Elle utilise les fonctions ft_strlen pour calculer la longueur des chaînes.
** Exemple(s):
** char dst[10] = "Hello";
** ft_strlcat(dst, " world!", 10); // renvoie 11 et dst vaut "Hello wor"
** char dst[10] = "Hello";
** ft_strlcat(dst, " world!", 15); // renvoie 11 et dst vaut "Hello world!"
** char dst[10] = "";
** ft_strlcat(dst, "Bonjour", 5); // renvoie 7 et dst vaut "Bonj"
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
