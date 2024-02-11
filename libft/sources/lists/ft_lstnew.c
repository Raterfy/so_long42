/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:08:26 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:04:00 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstnew
** Paramètre(s): void *content
** Valeur de retour: t_list *
** Description: Cette fonction crée un nouvel élément d'une liste chaînée.
** Elle prend en paramètre un pointeur sur le contenu de l'élément à créer.
** Elle alloue de la mémoire pour l'élément avec la fonction malloc 
	et y copie le contenu passé en paramètre.
** Elle initialise le pointeur sur l'élément suivant à NULL.
** Elle renvoie un pointeur sur le nouvel élément ou NULL si l'allocation échoue.
** Exemple(s):
** t_list *new = ft_lstnew("hello"); // new -> "hello" -> NULL
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
