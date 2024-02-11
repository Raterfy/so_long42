/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:50:13 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 00:21:49 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_itoa
** Paramètre(s): int n
** Valeur de retour: char *
** Description: Cette fonction convertit un nombre entier en 
	une chaîne de caractères.
** Elle alloue de la mémoire pour la chaîne avec la fonction malloc.
** Elle utilise une fonction auxiliaire ft_intlen pour calculer 
	la longueur de la chaîne à allouer.
** Elle parcourt le nombre de la droite vers la gauche et écrit 
	les chiffres dans la chaîne en tenant compte du signe.
** Elle renvoie la chaîne convertie ou NULL si l'allocation échoue.
** Exemple(s):
** ft_itoa(42) -> "42"
** ft_itoa(-123) -> "-123"
** ft_itoa(0) -> "0"
*/
static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
