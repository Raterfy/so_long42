/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:18:00 by robhak            #+#    #+#             */
/*   Updated: 2024/02/14 17:32:01 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*exit;
	void	*wall;
	void	*ground;
	void	*player;
	void	*collectible;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		count_c;
	int		count_e;
	int		count_p;
	int		get_c;
	int		count_moves;
}			t_data;

// Free
void		free_map(t_data *data);
void		free_img(t_data *data);
int			close_game(t_data *data);
// Parsing
void		dfs(t_data *data, int y, int x);
int			is_path_valid(t_data *data);
int			map_error(t_data *data);
int			is_ber_file(char *argv);

char		**map_cpy(char **map);
char		**create_map(int fd, t_data *data);
void		game(t_data *data);
void		free_map(t_data *data);
void		check_number_of_collectible(t_data *data, int y, int x);
void		find_player(t_data *data);
int			count_elements(t_data *data, char c);
int			count_elements(t_data *data, char c);
int			get_line_len(char *str);
int			keyhook(int keycode, t_data *data);

#endif