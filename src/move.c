/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:18:26 by robhak            #+#    #+#             */
/*   Updated: 2024/02/14 17:34:26 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

void	move_w(int keycode, t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		if (!is_and_exit(data, data->player_y - 1, data->player_x))
		{
			data->count_moves++;
			ft_printf("Moves: %d\n", data->count_moves);
		}
	}
}

void	move_s(int keycode, t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		if (!is_and_exit(data, data->player_y + 1, data->player_x))
		{
			data->count_moves++;
			ft_printf("Moves: %d\n", data->count_moves);
		}
	}
}

void	move_a(int keycode, t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		if (!is_and_exit(data, data->player_y, data->player_x - 1))
		{
			data->count_moves++;
			ft_printf("Moves: %d\n", data->count_moves);
		}
	}
}

void	move_d(int keycode, t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		if (!is_and_exit(data, data->player_y, data->player_x + 1))
		{
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
		move_w(keycode, data);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_d(keycode, data);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_s(keycode, data);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_a(keycode, data);
	return (0);
}
