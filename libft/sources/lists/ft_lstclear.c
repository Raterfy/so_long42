/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:12:33 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:52:26 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstclear
** Paramètre(s): t_list **lst, void (*del)(void*)
** Valeur de retour: void
** Description: Cette fonction supprime et libère la mémoire de 
	tous les éléments d'une liste chaînée.
** Elle prend en paramètre un pointeur sur le pointeur du premier élément 
	de la liste et un pointeur sur une fonction qui permet de libérer 
	le contenu de chaque élément.
** Elle vérifie si les paramètres sont valides, sinon elle ne fait rien.
** Elle parcourt la liste en sauvegardant le pointeur sur l'élément suivant 
	et en appelant la fonction ft_lstdelone pour supprimer 
	et libérer l'élément courant.
** Elle met à jour le pointeur du premier élément à chaque itération 
	jusqu'à ce que la liste soit vide.
** Exemple(s):
** t_list *lst = ft_lstnew("hello");
** ft_lstadd_back(&lst, ft_lstnew("world"));
** ft_lstclear(&lst, free); // lst -> NULL
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
