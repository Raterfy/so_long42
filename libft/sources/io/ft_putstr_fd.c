/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:00:18 by robhak            #+#    #+#             */
/*   Updated: 2023/06/06 18:19:03 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_putstr_fd
** Paramètre(s): char *s, int fd
** Valeur de retour: void
** Description: Cette fonction écrit une chaîne de caractères 
	sur un descripteur de fichier.
** Elle prend en paramètre la chaîne à écrire et le descripteur 
	de fichier sur lequel écrire.
** Elle utilise la fonction write pour écrire la chaîne.
** Elle ne fait rien si la chaîne est nulle.
** Exemple(s):
** ft_putstr_fd("Hello", 1); // écrit "Hello" sur la sortie standard
** ft_putstr_fd("World", 2); // écrit "World" sur la sortie d'erreur
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}
