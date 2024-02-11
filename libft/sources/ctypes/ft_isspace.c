/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:52:16 by robhak            #+#    #+#             */
/*   Updated: 2023/05/29 14:27:34 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_isspace
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction teste si le caractère c est un caractère 
** d'espacement.
** Elle compare la valeur de c avec les valeurs ASCII correspondant aux 
** caractères d'espacement
** (espace, saut de page, tabulation horizontale, saut de ligne, retour 
** chariot et tabulation verticale).
** Elle renvoie 1 si c est un caractère d'espacement, 0 sinon.
** Exemple(s):
** ft_isspace(' ') -> 1
** ft_isspace('\t') -> 1
** ft_isspace('a') -> 0
*/
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v');
}
