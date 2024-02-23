/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_there_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:52:24 by robhak            #+#    #+#             */
/*   Updated: 2024/02/23 20:03:18 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

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

int	is_path_valid(t_data *data)
{
	int		i;
	int		j;
	int		pos[2];
	char	**copy;

	initialize_map_data(data);
	copy = copy_map(data);
	if (!copy)
		return (0);
	findplayer(pos, copy);
	floodfill(pos[0], pos[1], copy);
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

static void	flood_fill2(int x, int y, char **map, int *reachable_targets,
		int total_targets, int map_height, int map_width)
{
	// Base cases
	if (x < 0 || y < 0 || x >= map_height || y >= map_width)
		return ;
	if (map[x][y] == '1' || map[x][y] == '0')
		return ;
	if (map[x][y] == 'C' || map[x][y] == 'E')
		(*reachable_targets)++;
	map[x][y] = '0';
	flood_fill2(x + 1, y, map, reachable_targets, total_targets, map_height,
		map_width);
	flood_fill2(x - 1, y, map, reachable_targets, total_targets, map_height,
		map_width);
	flood_fill2(x, y + 1, map, reachable_targets, total_targets, map_height,
		map_width);
	flood_fill2(x, y - 1, map, reachable_targets, total_targets, map_height,
		map_width);
}

void	check_adjacent_cells(int x, int y, char **map, int *reachable_targets,
		t_data *data)
{
	// Check the cell above the player
	if (x - 1 >= 0 && map[x - 1][y] != '1' && (map[x - 1][y] == 'C' || map[x
			- 1][y] == 'E'))
		(*reachable_targets)++;
	// Check the cell to the right of the player
	if (map[x][y + 1] != '1' && (map[x][y + 1] == 'C' || map[x][y + 1] == 'E'))
		(*reachable_targets)++;
	// Check the cell below the player
	if (x + 1 < data->map_height && map[x + 1][y] != '1' && (map[x
			+ 1][y] == 'C' || map[x + 1][y] == 'E'))
		(*reachable_targets)++;
	// Check the cell to the left of the player
	if (y - 1 >= 0 && map[x][y - 1] != '1' && (map[x][y - 1] == 'C' || map[x][y
			- 1] == 'E'))
		(*reachable_targets)++;
}

int	is_map_solvable(t_data *data)
{
	int reachable_targets;
	int total_targets;
	char **copy;

	reachable_targets = 0;
	total_targets = data->count_c + data->count_e;
	// Initialize map dimensions
	initialize_map_dimensions(data);
	// Create a copy of the map
	copy = copy_map(data);
	if (!copy)
		return (0);
	// Perform flood fill from the player's position
	flood_fill2(data->player_pos_x, data->player_pos_y, copy,
		&reachable_targets, total_targets, data->map_height, data->map_width);
	// Check the cells adjacent to the player
	check_adjacent_cells(data->player_pos_x, data->player_pos_y, copy,
		&reachable_targets, data);
	// Free the copied map
	free_map2(copy, data->map_height);
	// If all targets are reachable, the map is solvable
	return (reachable_targets == total_targets);
}git