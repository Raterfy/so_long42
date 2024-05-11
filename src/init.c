/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:31:08 by robhak            #+#    #+#             */
/*   Updated: 2024/05/11 11:28:17 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * Initializes the images used in the game.
 */
void	init_img(t_data *data)
{
	int	img_width;
	int	img_height;

	data->player = mlx_xpm_file_to_image(data->mlx, "assets/fusee_up.xpm",
			&img_width, &img_height);
	data->player_down = mlx_xpm_file_to_image(data->mlx, "assets/fusee_bot.xpm",
			&img_width, &img_height);
	data->player_left = mlx_xpm_file_to_image(data->mlx,
			"assets/fusee_left.xpm", &img_width, &img_height);
	data->player_right = mlx_xpm_file_to_image(data->mlx,
			"assets/fusee_right.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "assets/asteroid.xpm",
			&img_width, &img_height);
	data->ground = mlx_xpm_file_to_image(data->mlx, "assets/vide.xpm",
			&img_width, &img_height);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "assets/soucoupe.xpm",
			&img_width, &img_height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm", &img_width,
			&img_height);
}

/*
 * Sets the image for a specific item on the map.
 */
void	set_item(t_data *data, t_pos pos)
{
	if (data->map[pos.y][pos.x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collectible,
			pos.x * 50, pos.y * 50);
	}
	else if (data->map[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, pos.x
			* 50, pos.y * 50);
	else if (data->map[pos.y][pos.x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, pos.x
			* 50, pos.y * 50);
		data->player_x = pos.x;
		data->player_y = pos.y;
	}
}

/*
 * Sets the images for all items on the map.
 */
void	set_img(t_data *data)
{
	t_pos	pos;

	pos.y = 0;
	while (data->map[pos.y])
	{
		pos.x = 0;
		while (data->map[pos.y][pos.x])
		{
			if (data->map[pos.y][pos.x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
					pos.x * 50, pos.y * 50);
			else
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
					pos.x * 50, pos.y * 50);
				set_item(data, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

/*
 * Sets up the game, including key and close window hooks.
 */
void	game(t_data *data)
{
	data->get_c = 0;
	data->count_moves = 0;
	mlx_hook(data->mlx_win, 2, 1L << 0, keyhook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, close_game, data);
}

/*
 * Initializes the game, including the window and images,
	and starts the game loop.
 */
void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free(data->mlx);
		return ;
	}
	data->mlx_win = mlx_new_window(data->mlx, data->width * 50, data->height
			* 50, "so_long");
	init_img(data);
	set_img(data);
	game(data);
	mlx_loop(data->mlx);
}
