/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:32:18 by robhak            #+#    #+#             */
/*   Updated: 2024/02/14 17:29:35 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_map_rectangular(t_data *data)
{
	int	y;
	int	len;

	len = get_line_len(data->map[0]);
	y = 0;
	while (data->map[y])
	{
		if (get_line_len(data->map[y]) != len)
		{
			write(2, "Error: The map is not rectangular\n", 34);
			return (false);
		}
		y++;
	}
	return (true);
}

static bool	is_map_closed(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if ((y == 0 || y == data->height - 1 || x == 0 || x == data->width
					- 1) && data->map[y][x] != '1')
			{
				write(2, "Error: The map is not closed\n", 29);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

int	wall_error(t_data *data, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j++] != '1')
			return (0);
	}
	i++;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][len] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (data->map[i - 1][j])
	{
		if (data->map[i - 1][j++] != '1')
			return (0);
	}
	return (1);
}

int	check_forbidden_characters(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'C' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'P')
			{
				write(2, "Error: Forbidden character in the map\n", 40);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

bool	check_element_counts(t_data *data)
{
	if (data->count_e != 1)
	{
		ft_printf("Error: The map should have exactly one exit.\n");
		return (false);
	}
	if (data->count_c < 1)
	{
		ft_printf("Error: The map should have at least one collectible.\n");
		return (false);
	}
	if (data->count_p != 1)
	{
		ft_printf("Error: The map should have one starting position.\n");
		return (false);
	}
	return (true);
}

void	dfs(t_data *data, int y, int x)
{
	data->count_p = 0;
	data->count_e = 0;
	data->count_c = 0;
	if (y < 0 || y >= data->height || x < 0 || x >= data->width
		|| data->map[y][x] == '1')
		return ;
	if (data->map[y][x] == 'C')
		data->count_c++;
	if (data->map[y][x] == 'E')
		data->count_e++;
	data->map[y][x] = 'V';
	dfs(data, y - 1, x);
	dfs(data, y + 1, x);
	dfs(data, y, x - 1);
	dfs(data, y, x + 1);
}

int	is_path_valid(t_data *data)
{
	int	y;
	int	x;
	int	total_collectibles;

	y = 0;
	data->count_c = 0;
	data->count_e = 0;
	total_collectibles = count_elements(data, 'C');
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				dfs(data, y, x);
				return (data->count_c == total_collectibles
					&& data->count_e == 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	map_error(t_data *data)
{
	int	cpy;

	// int	len;
	// len = get_line_len(data->map[0]) - 1;
	cpy = NULL;
	if (!check_element_counts(data) || !check_forbidden_characters(data))
		return (0);
	if (!is_map_rectangular(data))
		return (0);
	if (!is_map_closed(data))
		return (0);
	cpy = map_cpy(data->map);
	if (!cpy)
		return (0);
	if (!is_path_valid(data))
	{
		free_map(data);
		free(cpy);
		return (0);
	}
	return (1);
}
