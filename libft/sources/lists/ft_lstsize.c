/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:09:33 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:06:03 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_lstsize
** Paramètre(s): t_list *lst
** Valeur de retour: int
** Description: Cette fonction renvoie le nombre d'éléments d'une liste chaînée.
** Elle prend en paramètre un pointeur sur le premier élément de la liste.
** Elle parcourt la liste en incrémentant un compteur à chaque itération.
** Elle renvoie la valeur du compteur à la fin du parcours.
** Exemple(s):
** t_list *lst = ft_lstnew("hello");
** ft_lstadd_back(&lst, ft_lstnew("world"));
** ft_lstsize(lst); // renvoie 2
*/
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
