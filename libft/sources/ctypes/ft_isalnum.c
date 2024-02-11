/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:39 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:13:42 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_isalnum
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction teste si le caractère c 
	est alphanumérique, c'est-à-dire s'il est une lettre ou un chiffre.
** Elle utilise les fonctions ft_isalpha et ft_isdigit pour effectuer ce test.
** Elle renvoie 1 si c est alphanumérique, 0 sinon.
** Exemple(s):
** ft_isalnum('a') -> 1
** ft_isalnum('5') -> 1
** ft_isalnum('@') -> 0
*/
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
