/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:26 by robhak            #+#    #+#             */
/*   Updated: 2023/06/06 17:57:32 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Nom de la fonction: ft_atoi
** Paramètre(s): const char *nptr
** Valeur de retour: int
** Description: Cette fonction convertit une chaîne 
	de caractères en un nombre entier.
** Si la chaîne commence par des espaces ou des 
	caractères de contrôle, ils sont ignorés.
** Si la chaîne commence par un signe '+' ou '-', 
	il est pris en compte pour le signe du nombre.
** Si la chaîne contient des caractères non numériques 
	après les chiffres, ils sont ignorés.
** Si la chaîne est vide ou ne contient pas 
	de chiffres, la fonction renvoie 0.
** Exemple(s):
** ft_atoi("42") -> 42
** ft_atoi("   -123") -> -123
** ft_atoi("+3.14") -> 3
** ft_atoi("abc") -> 0
*/
int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}

long long int	ft_long_atoi(const char *nptr)
{
	long long int	result;
	long long int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * result);
}
