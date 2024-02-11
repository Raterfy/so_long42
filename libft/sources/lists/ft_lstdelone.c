/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:11:57 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:56:28 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstdelone
** Paramètre(s): t_list *lst, void (*del)(void*)
** Valeur de retour: void
** Description: Cette fonction supprime et libère la mémoire d'un élément 
	d'une liste chaînée.
** Elle prend en paramètre un pointeur sur l'élément à supprimer et un pointeur 
	sur une fonction qui permet de libérer le contenu de l'élément.
** Elle vérifie si les paramètres sont valides, sinon elle ne fait rien.
** Elle appelle la fonction del avec le contenu de l'élément comme argument 
	et libère la mémoire allouée pour l'élément avec la fonction free.
** Exemple(s):
** t_list *lst = ft_lstnew("hello");
** ft_lstdelone(lst, free); // lst -> NULL
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
