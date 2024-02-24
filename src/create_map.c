/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:10:46 by robhak            #+#    #+#             */
/*   Updated: 2024/02/24 11:04:17 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/get_next_line.h"

void	update_map_stats(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'C')
		data->count_c++;
	if (data->map[y][x] == 'E')
		data->count_e++;
	if (data->map[y][x] == 'P')
		data->count_p++;
}

/*
 * Counts the number of 'P', 'C', 'E' characters and calculates
 * the dimensions of the map.
 */
void	map_stats(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->count_p = 0;
	data->count_c = 0;
	data->count_e = 0;
	data->height = 0;
	data->width = 0;
	if (data->map == NULL)
		return ;
	if (data->map[y])
		data->width = get_line_len(data->map[y]);
	while (data->map && data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			update_map_stats(data, y, x);
			x++;
		}
		data->height++;
		y++;
	}
}

/*
 * Joins two map lines with a '/' separator.
 */
char	*join_map_line(char *s1, char *s2)
{
	int		i;
	int		size;
	char	*tab;

	i = 0;
	size = (get_line_len(s1) + get_line_len(s2));
	tab = malloc(sizeof(char) * size + 2);
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	tab[size] = '/';
	tab[size + 1] = '\0';
	if (s1)
		free(s1);
	return (tab);
}

/*
 * Reads the map from a file and stores it in 'data'.
 */
void	read_map_from_file(int fd, t_data *data)
{
	char	*line;
	char	*map_line;

	line = NULL;
	map_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_line = join_map_line(map_line, line);
		free(line);
	}
	data->map = ft_split(map_line, '/');
	free(map_line);
}

/*
 * Reads the map from a file, calculates its stats, checks for errors,
 * and returns the map.
 */
char	**create_map(int fd, t_data *data)
{
	read_map_from_file(fd, data);
	close(fd);
	map_stats(data);
	if (map_error(data) == 0)
		return (NULL);
	return (data->map);
}
