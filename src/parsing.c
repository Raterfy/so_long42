/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:32:18 by robhak            #+#    #+#             */
/*   Updated: 2024/02/11 13:07:18 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_ber_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i < 4)
		return (0);
	if (argv[i - 4] == '.' && argv[i - 3] == 'b' && argv[i - 2] == 'e' && argv[i
		- 1] == 'r')
		return (1);
	return (0);
}

static bool	is_map_rectangular(t_data *data)
{
	int	y;
	int	len;

	len = ft_strlen(data->map[0]);
	y = 0;
	while (data->map[y])
	{
		if (ft_strlen(data->map[y]) != len)
			return (false);
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
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static int	count_elements(t_data *data, char c)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			if (data->map[y][x] == c)
				count++;
	}
	return (count);
}

bool	check_element_counts(t_data *data)
{
	if (count_elements(data, 'E') != 1)
	{
		ft_printf("Error: The map should have exactly one exit.\n");
		return (false);
	}
	if (count_elements(data, 'C') < 1)
	{
		ft_printf("Error: The map should have at least one collectible.\n");
		return (false);
	}
	if (count_elements(data, 'P') != 1)
	{
		ft_printf("Error: The map should have exactly one starting position.\n");
		return (false);
	}
	return (true);
}

bool	is_map_valid(t_data *data)
{
	if (!is_map_rectangular(data))
	{
		ft_printf("Error: The map is not rectangular.\n");
		return (false);
	}
	if (!is_map_closed(data))
	{
		ft_printf("Error: The map is not closed.\n");
		return (false);
	}
	if (!check_element_counts(data))
		return (false);
	return (true);
}

void	dfs(t_data *data, int y, int x)
{
	if (y < 0 || y >= data->height || x < 0 || x >= data->width
		|| data->map[y][x] == '1')
		return ;
	if (data->map[y][x] == 'C')
		data->count_C++;
	if (data->map[y][x] == 'E')
		data->count_E++;
	data->map[y][x] = 'V';
	dfs(data, y - 1, x);
	dfs(data, y + 1, x);
	dfs(data, y, x - 1);
	dfs(data, y, x + 1);
}

bool	is_path_valid(t_data *data)
{
	int	y;
	int	x;
	int	total_collectibles;

	y = 0;
	data->count_C = 0;
	data->count_E = 0;
	total_collectibles = count_elements(data, 'C');
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				dfs(data, y, x);
				return (data->count_C == total_collectibles
					&& data->count_E == 1);
			}
			x++;
		}
		y++;
	}
	return (false);
}
