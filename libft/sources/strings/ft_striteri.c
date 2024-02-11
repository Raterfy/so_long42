/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:58:05 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 02:09:05 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_striteri
** Paramètre(s): char *s, void (*f)(unsigned int, char*)
** Valeur de retour: void
** Description: Cette fonction applique la fonction f à chaque caractère 
	de la chaîne s en passant son index en premier argument.
** Elle prend en paramètre la chaîne à parcourir et la fonction à appliquer.
** Elle ne fait rien si la chaîne ou la fonction sont nulles.
** Exemple(s):
** void print_index_and_char(unsigned int i, char *c)
** {
**     printf("index = %u, char = %c\n", i, *c);
** }
**
** ft_striteri("Hello", print_index_and_char); // affiche :
** // index = 0, char = H
** // index = 1, char = e
** // index = 2, char = l
** // index = 3, char = l
** // index = 4, char = o
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
