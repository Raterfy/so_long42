/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:18:26 by robhak            #+#    #+#             */
/*   Updated: 2024/02/19 13:45:41 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

static void	move_w(t_data *data)
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
}

static void	move_s(t_data *data)
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
}

static void	move_a(t_data *data)
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
}

static void	move_d(t_data *data)
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
}

int	keyhook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_game(data);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_w(data);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_d(data);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_s(data);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_a(data);
	return (0);
}
