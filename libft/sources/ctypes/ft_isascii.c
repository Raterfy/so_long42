/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:49 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:16:42 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_isascii
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction teste si le caractère c est 
	un caractère ASCII, c'est-à-dire s'il a une valeur entre 0 et 127 inclus.
** Elle compare la valeur de c avec les bornes de la table ASCII.
** Elle renvoie 1 si c est un caractère ASCII, 0 sinon.
** Exemple(s):
** ft_isascii('A') -> 1
** ft_isascii(127) -> 1
** ft_isascii(128) -> 0
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
