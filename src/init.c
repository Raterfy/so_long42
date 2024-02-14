/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:31:08 by robhak            #+#    #+#             */
/*   Updated: 2024/02/14 17:33:59 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_data *data)
{
	int	img_width;
	int	img_height;

	data->player = mlx_xpm_file_to_image(data->mlx, "assets/fusee_up.xpm",
			&img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "assets/asteroid.xpm",
			&img_width, &img_height);
	data->ground = mlx_xpm_file_to_image(data->mlx, "assets/vide.xpm",
			&img_width, &img_height);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "assets/soucoupe.xpm",
			&img_width, &img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm", &img_width,
			&img_height);
}

void	ft_set_item(t_map *map, t_pos pos)
{
	if (map->map_tab[pos.y][pos.x] == 'C')
	{
		if ((pos.y * pos.x) % 2 == 0)
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->berry, pos.x * 24, pos.y * 24);
		else
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->berry2, pos.x * 24, pos.y * 24);
	}
	else if (map->map_tab[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->exit, pos.x * 24, pos.y * 24);
	else if (map->map_tab[pos.y][pos.x] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_right, pos.x * 24, pos.y * 24);
		map->p_x = pos.x;
		map->p_y = pos.y;
	}
}

void	ft_set_img(t_map *map)
{
	t_pos	pos;

	pos.y = 0;
	while (map->map_tab[pos.y])
	{
		pos.x = 0;
		while (map->map_tab[pos.y][pos.x])
		{
			if (map->map_tab[pos.y][pos.x] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->tree, pos.x * 24, pos.y * 24);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->ground, pos.x * 24, pos.y * 24);
				ft_set_item(map, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free(data->mlx);
		return ;
	}
	data->mlx_win = mlx_new_window(data->mlx, data->width * 50,
			data->height * 50, "so_long");
	init_img(data);
	set_img(data);
	game(data);
	mlx_loop(data->mlx);
}
