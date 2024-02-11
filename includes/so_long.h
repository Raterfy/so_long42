/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:18:00 by robhak            #+#    #+#             */
/*   Updated: 2024/02/11 11:45:14 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*textures[5];
	char 		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int 		count_C;
	int			count_E;
	int			count_moves;
}				t_data;

int		is_ber_file(char *argv);
bool	is_map_valid(t_data *data);
void	check_number_of_collectible(t_data *data, int y, int x);

#endif