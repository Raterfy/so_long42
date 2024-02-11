/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:13:33 by robhak            #+#    #+#             */
/*   Updated: 2023/12/28 21:20:46 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstmap
** Paramètre(s): t_list *lst, void *(*f)(void *), void (*del)(void *)
** Valeur de retour: t_list *
** Description: Cette fonction crée une nouvelle liste chaînée en appliquant 
	une fonction f au contenu de chaque élément de la liste originale.
** Elle prend en paramètre un pointeur sur le premier élément de la liste 
	originale, un pointeur sur la fonction f et un pointeur sur une fonction del 
	qui permet de libérer le contenu des éléments en cas d'erreur.
** Elle vérifie si les paramètres sont valides, sinon elle renvoie NULL.
** Elle alloue de la mémoire pour chaque nouvel élément avec la fonction 
	ft_lstnew et y copie le résultat de l'application de f au contenu 
	de l'élément correspondant de la liste originale.
** Elle ajoute chaque nouvel élément à la fin de la nouvelle liste avec 
	la fonction ft_lstadd_back.
** Si l'allocation échoue, elle supprime et libère la mémoire de tous 
	les éléments déjà créés avec la fonction ft_lstclear et renvoie NULL.
** Elle renvoie un pointeur sur le premier élément de la nouvelle liste.
** Exemple(s):
** t_list *lst = ft_lstnew("hello");
** ft_lstadd_back(&lst, ft_lstnew("world"));
** t_list *new_lst = ft_lstmap(lst, &ft_strdup, &free); 
	new_lst -> "hello" -> "world" -> NULL
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
