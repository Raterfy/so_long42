/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:12 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:22:03 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_strlen
** Paramètre(s): const char *s
** Valeur de retour: size_t
** Description: Cette fonction calcule la longueur d'une chaîne de caractères, 
	sans compter le caractère nul de fin.
** Elle prend en paramètre la chaîne dont on veut connaître la longueur.
** Elle renvoie le nombre de caractères dans la chaîne.
** Exemple(s):
** ft_strlen("Hello"); // renvoie 5
** ft_strlen(""); // renvoie 0
*/
size_t	ft_strlen(const char *s)
{
	const char	*len;

	len = s;
	while (*len != '\0')
		len++;
	return (len - s);
}
