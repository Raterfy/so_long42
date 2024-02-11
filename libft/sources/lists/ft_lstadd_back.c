/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:11:32 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:42:49 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstadd_back
** Paramètre(s): t_list **lst, t_list *new
** Valeur de retour: void
** Description: Cette fonction ajoute un élément à la fin d'une liste chaînée.
** Elle prend en paramètre un pointeur sur le pointeur du premier élément de 
	la liste et un pointeur sur l'élément à ajouter.
** Elle vérifie si les paramètres sont valides, sinon elle ne fait rien.
** Si la liste est vide, elle fait pointer le premier élément sur 
	le nouvel élément.
** Sinon, elle utilise une fonction auxiliaire ft_lstlast pour trouver 
	le dernier élément de la liste et le faire pointer sur le nouvel élément.
** Exemple(s):
** t_list *lst = NULL;
** t_list *new = ft_lstnew("hello");
** ft_lstadd_back(&lst, new); // lst -> "hello" -> NULL
** t_list *new2 = ft_lstnew("world");
** ft_lstadd_back(&lst, new2); // lst -> "hello" -> "world" -> NULL
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
