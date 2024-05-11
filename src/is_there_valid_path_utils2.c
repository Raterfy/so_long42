/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_valid_path_utils2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:11:34 by robhak            #+#    #+#             */
/*   Updated: 2024/05/11 11:28:33 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

/*
 * Initializes the map data, including the start position and dimensions.
 */
void	initialize_map_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->start_x = i;
				data->start_y = j;
			}
			j++;
		}
		i++;
	}
	data->map_height = i;
	data->map_width = j;
}

/*
 * Performs a flood fill operation on the map, marking reachable cells.
 */
void	floodfill(int w, int l, char **map)
{
	map[w][l] = '1';
	if (map[w - 1][l] != '1')
		floodfill(w - 1, l, map);
	if (map[w + 1][l] != '1')
		floodfill(w + 1, l, map);
	if (map[w][l - 1] != '1')
		floodfill(w, l - 1, map);
	if (map[w][l + 1] != '1')
		floodfill(w, l + 1, map);
}

/*
 * Finds the player's position on the map.
 */
void	findplayer(int *pos, char **map)
{
	int	w;
	int	l;

	w = 0;
	while (map[w])
	{
		l = 0;
		while (map[w][l])
		{
			if (map[w][l] == 'P')
				break ;
			l++;
		}
		if (map[w][l] == 'P')
			break ;
		w++;
	}
	pos[0] = w;
	pos[1] = l;
}

/*
 * Checks if there is a valid path from the player to all collectibles 
 	and the exit.
*/
int	check_path(t_data *data, char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if ((data->map[i][j] == 'C' || data->map[i][j] == 'E')
				&& copy[i][j] != '0' && copy[i][j] != '1')
			{
				free_map2(copy, data->map_height);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map2(copy, data->map_height);
	return (1);
}
