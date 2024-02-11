/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:13:03 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:58:15 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstiter
** Paramètre(s): t_list *lst, void (*f)(void *)
** Valeur de retour: void
** Description: Cette fonction applique une fonction f au contenu de 
	chaque élément d'une liste chaînée.
** Elle prend en paramètre un pointeur sur le premier élément de 
	la liste et un pointeur sur la fonction f.
** Elle vérifie si les paramètres sont valides, sinon elle ne fait rien.
** Elle parcourt la liste en appelant la fonction f avec le contenu 
	de l'élément courant comme argument.
** Exemple(s):
** t_list *lst = ft_lstnew("hello");
** ft_lstadd_back(&lst, ft_lstnew("world"));
** ft_lstiter(lst, &ft_putstr); // affiche "helloworld"
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
