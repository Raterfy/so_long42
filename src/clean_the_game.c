/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_the_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:26:08 by robhak            #+#    #+#             */
/*   Updated: 2024/02/24 12:10:50 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_bfs_data(t_bfsdata *bfsdata)
{
	free_map2(bfsdata->map, bfsdata->map_height);
	free(bfsdata->reachable_targets);
	free(bfsdata);
}

void	free_map2(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(t_data *data)
{
	int	i;

	if (data->map == NULL)
		return ;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->player_down);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->player_right);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->ground);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->exit);
}

int	close_game(t_data *data)
{
	free_map(data);
	free_img(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
