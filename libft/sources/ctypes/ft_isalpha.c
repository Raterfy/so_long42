/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:41 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:15:59 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_isalpha
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction teste si le caractère c 
	est une lettre de l'alphabet, en majuscule ou en minuscule.
** Elle compare la valeur de c avec les intervalles 
	ASCII correspondant aux lettres.
** Elle renvoie 1 si c est une lettre, 0 sinon.
** Exemple(s):
** ft_isalpha('b') -> 1
** ft_isalpha('Z') -> 1
** ft_isalpha('9') -> 0
*/
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
