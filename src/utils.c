/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:21:48 by robhak            #+#    #+#             */
/*   Updated: 2024/05/11 11:37:28 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

/*
 * Returns the length of the line in the string up to the newline character.
 */
int	get_line_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

/*
 * Checks if the player has reached the exit and
	if all collectibles have been collected.
 * If so, prints a victory message and closes the game.
 * Returns 1 if the player has reached the exit
 * but not all collectibles have been collected, 0 otherwise.
 */
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

/*
 * Checks if the player has reached a collectible
   and increments the count of collected items if so.
*/
void	check_item(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'C')
		data->get_c++;
}

/*
 * Sets the ground image at the player's previous position
   and updates the map.
 */
void	set_ground(t_data *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground, x * 50, y
		* 50);
	data->map[data->player_y][data->player_x] = '0';
}

/*
 * Draws the player character in the new position,
   with the image depending on the direction of movement.
 */
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
