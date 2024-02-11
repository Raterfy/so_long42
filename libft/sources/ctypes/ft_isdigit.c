/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:51 by robhak            #+#    #+#             */
/*   Updated: 2023/05/29 14:23:32 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_isdigit
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction teste si le caractère c 
	est un chiffre décimal, entre '0' et '9'.
** Elle compare la valeur de c avec l'intervalle 
	ASCII correspondant aux chiffres.
** Elle renvoie 1 si c est un chiffre, 0 sinon.
** Exemple(s):
** ft_isdigit('5') -> 1
** ft_isdigit('a') -> 0
** ft_isdigit(' ') -> 0
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
