/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:21:48 by robhak            #+#    #+#             */
/*   Updated: 2024/02/23 15:50:43 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

int	get_line_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	is_and_exit(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'E')
	{
		if (data->get_c == data->count_c)
		{
			ft_printf("You won UwU!\n");
			close_game(data);
		}
		else
			return (1);
	}
	return (0);
}

void	check_item(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'C')
		data->get_c++;
}

void	set_ground(t_data *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, x * 50, y
		* 50);
	data->map[data->player_y][data->player_x] = '0';
}

void	draw_character(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
			data->player_x * 50, data->player_y * 50);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_down,
			data->player_x * 50, data->player_y * 50);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left,
			data->player_x * 50, data->player_y * 50);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_right,
			data->player_x * 50, data->player_y * 50);
}
