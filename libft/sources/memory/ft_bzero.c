/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:31 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:10:45 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_bzero
** Paramètre(s): void *s, size_t n
** Valeur de retour: void
** Description: Cette fonction remplit les n premiers octets 
	de la zone mémoire pointée par s avec des zéros.
** Elle utilise la fonction ft_memset pour effectuer cette opération.
** Si n est nul, la fonction ne fait rien.
** Exemple(s):
** char s[10] = "Hello";
** ft_bzero(s, 3); -> s = "\0\0\0lo"
** ft_bzero(s, 0); -> s = "\0\0\0lo"
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
