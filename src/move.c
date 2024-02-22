/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:18:26 by robhak            #+#    #+#             */
/*   Updated: 2024/02/22 15:54:40 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

static void	move_w(int keycode, t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		if (!is_and_exit(data, data->player_y - 1, data->player_x))
		{
			data->player_y--;
			check_item(data, data->player_y, data->player_x);
			set_ground(data, data->player_y + 1, data->player_x);
			data->count_moves++;
			ft_printf("Moves: %d\n", data->count_moves);
		}
	}
	draw_character(keycode, data);
}

static void	move_s(int keycode, t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		if (!is_and_exit(data, data->player_y + 1, data->player_x))
		{
			data->player_y++;
			check_item(data, data->player_y, data->player_x);
			set_ground(data, data->player_y - 1, data->player_x);
			data->count_moves++;
			ft_printf("Moves: %d\n", data->count_moves);
		}
	}
	draw_character(keycode, data);
}

static void	move_a(int keycode, t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		if (!is_and_exit(data, data->player_y, data->player_x - 1))
		{
			data->player_x--;
			check_item(data, data->player_y, data->player_x);
			set_ground(data, data->player_y, data->player_x + 1);
			data->count_moves++;
			ft_printf("Moves: %d\n", data->count_moves);
		}
	}
	draw_character(keycode, data);
}

static void	move_d(int keycode, t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		if (!is_and_exit(data, data->player_y, data->player_x + 1))
		{
			data->player_x++;
			check_item(data, data->player_y, data->player_x);
			set_ground(data, data->player_y, data->player_x - 1);
			data->count_moves++;
			ft_printf("Moves: %d\n", data->count_moves);
		}
	}
	draw_character(keycode, data);
}

int	keyhook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_w(keycode, data);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_d(keycode, data);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_s(keycode, data);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_a(keycode, data);
	return (0);
}
