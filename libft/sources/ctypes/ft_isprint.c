/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:54 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:20:10 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_isprint
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction teste si le caractère c est un caractère 
	imprimable, c'est-à-dire s'il a une valeur entre 32 et 126 inclus.
** Elle compare la valeur de c avec les bornes de la table ASCII 
	des caractères imprimables.
** Elle renvoie 1 si c est un caractère imprimable, 0 sinon.
** Exemple(s):
** ft_isprint('a') -> 1
** ft_isprint(' ') -> 1
** ft_isprint(127) -> 0
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
