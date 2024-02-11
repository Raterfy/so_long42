/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:27:38 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:49:57 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_tolower
** Paramètre(s): int c
** Valeur de retour: int
** Description: Cette fonction convertit une lettre 
	majuscule en minuscule si possible.
** Elle prend en paramètre un caractère c et renvoie 
	sa version minuscule si c est une lettre majuscule.
** Sinon, elle renvoie c inchangé.
** Elle utilise la table ASCII pour comparer et convertir les caractères.
** Exemple(s):
** ft_tolower('A'); // renvoie 'a'
** ft_tolower('z'); // renvoie 'z'
** ft_tolower('!'); // renvoie '!'
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
