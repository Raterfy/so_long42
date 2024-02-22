/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:32:18 by robhak            #+#    #+#             */
/*   Updated: 2024/02/22 15:12:10 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

// void	dfs(t_data *data, int y, int x)
// {
// 	data->count_p = 0;
// 	data->count_e = 0;
// 	data->count_c = 0;
// 	if (y < 0 || y >= data->height || x < 0 || x >= data->width
// 		|| data->map[y][x] == '1')
// 		return ;
// 	if (data->map[y][x] == 'C')
// 		data->count_c++;
// 	if (data->map[y][x] == 'E')
// 		data->count_e++;
// 	data->map[y][x] = 'V';
// 	dfs(data, y - 1, x);
// 	dfs(data, y + 1, x);
// 	dfs(data, y, x - 1);
// 	dfs(data, y, x + 1);
// }

// int	is_path_valid(t_data *data)
// {
// 	int	y;
// 	int	x;
// 	int	total_collectibles;

// 	y = 0;
// 	data->count_c = 0;
// 	data->count_e = 0;
// 	total_collectibles = count_elements(data, 'C');
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			if (data->map[y][x] == 'P')
// 			{
// 				dfs(data, y, x);
// 				return (data->count_c == total_collectibles
// 					&& data->count_e == 1);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

int	char_error(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1'
			&& data->map[i][j] != '0'
			&& data->map[i][j] != 'C'
			&& data->map[i][j] != 'E'
			&& data->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	entity_error(t_data *data)
{
	if (data->count_p != 1)
	{
		ft_printf("Error data must have one starting position\n");
		return (0);
	}
	else if (data->count_e != 1)
	{
		ft_printf("Error data must have one exit\n");
		return (0);
	}
	else if (data->count_c < 1)
	{
		ft_printf("Error data must have one collectible or more\n");
		return (0);
	}
	return (1);
}

int	form_error(t_data *data, int len)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (len != get_line_len(data->map[i]) - 1)
		{
			ft_printf("Error map must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
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

int	map_error(t_data *data)
{
	int	len;

	len = get_line_len(data->map[0]) - 1;
	if (!char_error(data))
	{
		ft_printf("Error Invalid character on data\n");
		return (0);
	}
	if (!form_error(data, len)
		|| !entity_error(data))
		return (0);
	else if (!wall_error(data, len))
	{
		ft_printf("Error nmap not closed\n");
		return (0);
	}
	return (1);
}