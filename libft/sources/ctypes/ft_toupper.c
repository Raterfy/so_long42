/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:41 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:50:50 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_toupper
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction convertit une lettre minuscule 
	en majuscule si possible.
** Elle prend en paramètre un caractère c et renvoie sa version 
	majuscule si c est une lettre minuscule.
** Sinon, elle renvoie c inchangé.
** Elle utilise la table ASCII pour comparer et convertir les caractères.
** Exemple(s):
** ft_toupper('a'); // renvoie 'A'
** ft_toupper('Z'); // renvoie 'Z'
** ft_toupper('?'); // renvoie '?'
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
