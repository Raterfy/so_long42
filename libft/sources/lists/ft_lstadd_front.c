/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:09:00 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:50:12 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstadd_front
** Paramètre(s): t_list **lst, t_list *new
** Valeur de retour: void
** Description: Cette fonction ajoute un élément au début d'une liste chaînée.
** Elle prend en paramètre un pointeur sur le pointeur du premier élément
	de la liste et un pointeur sur l'élément à ajouter.
** Elle vérifie si les paramètres sont valides, sinon elle ne fait rien.
** Elle fait pointer le nouvel élément sur le premier élément de la liste 
	et met à jour le pointeur du premier élément.
** Exemple(s):
** t_list *lst = NULL;
** t_list *new = ft_lstnew("hello");
** ft_lstadd_front(&lst, new); // lst -> "hello" -> NULL
** t_list *new2 = ft_lstnew("world");
** ft_lstadd_front(&lst, new2); // lst -> "world" -> "hello" -> NULL
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
