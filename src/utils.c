/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:21:48 by robhak            #+#    #+#             */
/*   Updated: 2024/02/14 17:35:54 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_line_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	count_lines(char **map)
{
	int	line_count;

	line_count = 0;
	while (map[line_count])
		line_count++;
	return (line_count);
}

char	**map_cpy(char **map)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	j = count_lines(map);
	cpy = ft_calloc(j + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	while (map[i])
	{
		cpy[i] = ft_strdup(map[i]);
		if (!cpy[i])
		{
			while (i >= 0)
				free(cpy[i--]);
			free(cpy);
			return (NULL);
		}
		i++;
	}
	return (cpy);
}

int	count_elements(t_data *data, char c)
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

void	find_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	is_ber_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i < 4)
		return (0);
	if (argv[i - 4] == '.' && argv[i - 3] == 'b' && argv[i - 2] == 'e'
		&& argv[i - 1] == 'r')
		return (1);
	return (0);
}
