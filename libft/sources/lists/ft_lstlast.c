/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:09:57 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:59:46 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstlast
** Paramètre(s): t_list *lst
** Valeur de retour: t_list *
** Description: Cette fonction renvoie un pointeur sur le dernier 
	élément d'une liste chaînée.
** Elle prend en paramètre un pointeur sur le premier élément de la liste.
** Elle vérifie si la liste est vide, sinon elle renvoie NULL.
** Elle parcourt la liste jusqu'à trouver l'élément qui n'a pas 
	de successeur et le renvoie.
** Exemple(s):
** t_list *lst = ft_lstnew("hello");
** ft_lstadd_back(&lst, ft_lstnew("world"));
** ft_lstlast(lst); // renvoie un pointeur sur l'élément "world"
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
