/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:32:18 by robhak            #+#    #+#             */
/*   Updated: 2024/02/14 17:04:03 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game(t_data *data)
{
	data->count_moves = 0;
	data->get_c = 0;
	mlx_hook(data->mlx_win, 2, 1L << 0, keyhook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, close_game, data);
	mlx_loop(data->mlx);
}
