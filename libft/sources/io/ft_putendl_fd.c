/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:06:09 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:30:58 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_putendl_fd
** Paramètre(s): char *s, int fd
** Valeur de retour: void
** Description: Cette fonction écrit une chaîne de caractères suivie 
	d'un saut de ligne sur un descripteur de fichier.
** Elle prend en paramètre la chaîne à écrire et le descripteur 
	de fichier sur lequel écrire.
** Elle utilise les fonctions ft_putstr_fd et ft_putchar_fd 
	pour écrire la chaîne et le saut de ligne.
** Elle ne fait rien si la chaîne est nulle.
** Exemple(s):
** ft_putendl_fd("Hello", 1); // écrit "Hello\n" sur la sortie standard
** ft_putendl_fd("World", 2); // écrit "World\n" sur la sortie d'erreur
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
