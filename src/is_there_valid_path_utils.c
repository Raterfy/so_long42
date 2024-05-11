/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_valid_path_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:09:32 by robhak            #+#    #+#             */
/*   Updated: 2024/04/09 14:47:35 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

/*
 * Creates a copy of the given map line.
 */
char	*copy_map_line(char *src, int width)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (width + 1));
	if (!copy)
		return (NULL);
	while (i < width)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
 * Creates a copy of the given map.
 */
char	**copy_map(t_data *data)
{
	int		i;
	char	**copy;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!copy)
		return (NULL);
	while (i < data->map_height)
	{
		copy[i] = copy_map_line(data->map[i], data->map_width);
		if (!copy[i])
		{
			free_map2(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

/*
 * Initializes the dimensions of the map and the player's position.
 */
void	initialize_map_dimensions(t_data *data)
{
	int	j;

	data->map_height = 0;
	data->map_width = 0;
	data->player_pos_x = -1;
	data->player_pos_y = -1;
	if (data->map != NULL)
	{
		while (data->map[data->map_height])
		{
			j = 0;
			while (data->map[data->map_height][j])
			{
				if (data->map[data->map_height][j] == 'P')
				{
					data->player_pos_x = data->map_height;
					data->player_pos_y = j;
				}
				j++;
			}
			data->map_height++;
		}
		data->map_width = j;
	}
}

/*
 * Performs a breadth-first search on the map from the given position.
 */
void	bfs(int x, int y, t_bfsdata *data)
{
	if (x < 0 || y < 0 || x >= data->map_height || y >= data->map_width)
		return ;
	if (data->map[x][y] == '1' || data->map[x][y] == 'V'
		|| data->map[x][y] == 'E')
		return ;
	if (data->map[x][y] == 'C')
		(*data->reachable_targets)++;
	data->map[x][y] = 'V';
	bfs(x + 1, y, data);
	bfs(x - 1, y, data);
	bfs(x, y + 1, data);
	bfs(x, y - 1, data);
}

/*
 * Allocates and initializes a t_bfsdata structure.
 */
t_bfsdata	*init_bfs_data(t_data *data)
{
	t_bfsdata	*bfsdata;

	bfsdata = (t_bfsdata *)malloc(sizeof(t_bfsdata));
	if (!bfsdata)
		return (NULL);
	bfsdata->map = copy_map(data);
	if (!bfsdata->map)
	{
		free(bfsdata);
		return (NULL);
	}
	bfsdata->reachable_targets = (int *)malloc(sizeof(int));
	if (!bfsdata->reachable_targets)
	{
		free_map2(bfsdata->map, data->map_height);
		free(bfsdata);
		return (NULL);
	}
	*bfsdata->reachable_targets = 0;
	bfsdata->total_targets = data->count_c;
	bfsdata->map_height = data->map_height;
	bfsdata->map_width = data->map_width;
	return (bfsdata);
}
