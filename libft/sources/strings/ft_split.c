/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:26:22 by robhak            #+#    #+#             */
/*   Updated: 2023/05/07 01:58:55 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Nom de la fonction: ft_split
** Paramètre(s): char const *s, char c
** Valeur de retour: char **
** Description: Cette fonction découpe une chaîne de caractères 
	selon un caractère délimiteur et renvoie un tableau de chaînes 
	de caractères résultant de la découpe.
** Elle prend en paramètre la chaîne à découper et le caractère délimiteur.
** Elle utilise les fonctions malloc, free et ft_substr 
	pour allouer et libérer la mémoire.
** Elle renvoie NULL si la chaîne est nulle ou si l'allocation échoue.
** Elle compte le nombre de mots dans la chaîne avec la fonction ft_count_words.
** Elle calcule la longueur de chaque mot avec la fonction ft_wordlen.
** Elle libère le tableau en cas d'erreur avec la fonction free_strs.
** Exemple(s):
** ft_split("Hello world!", ' '); // renvoie ["Hello", "world!", NULL]
** ft_split("Bonjour,comment allez-vous?", ','); 
	// renvoie ["Bonjour", "comment allez-vous?", NULL]
** ft_split("", 'a'); // renvoie [NULL]
*/
static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (count);
}

static void	*free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

//strs[count] = NULL;parce que \0 n'est pas une valeur de pointeur valide
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	strs[count] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			strs[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!strs[i++])
				return (free_strs(strs));
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (strs);
}
