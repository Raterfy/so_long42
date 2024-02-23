/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:18:00 by robhak            #+#    #+#             */
/*   Updated: 2024/02/23 19:40:56 by robhak           ###   ########.fr       */
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
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*collectible;
	char	**map;
	int		width;
	int		height;
	int		map_height;
	int		map_width;
	int		start_x;
	int		start_y;
	int		player_x;
	int		player_y;
	int		player_pos_x;
	int		player_pos_y;
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
void		free_map2(char **map, int height);

// Parsing
int			map_error(t_data *data);
int			wall_error(t_data *data, int len);
int			is_rectangle(t_data *data, int len);
int			entity_error(t_data *data);
int			char_error(t_data *data);
int			is_ber_file(char *argv);
int			count_elements(t_data *data, char c);

// valid_path
int			is_path_valid(t_data *data);
int			find_path(int x, int y, char **map, t_data *data);
int			is_valid(int x, int y, char **map, t_data *data);
void		initialize_map_data(t_data *data);
char		*copy_map_line(char *src, int width);
char		**copy_map(t_data *data);
int			are_all_targets_reachable(char **map, t_data *data);
void		restore_map(char **map, t_data *data);
int			find_player_position(t_data *data, int *x, int *y);
int			is_map_solvable(t_data *data);
void		initialize_map_dimensions(t_data *data);

// Utils
void		check_item(t_data *data, int y, int x);
void		set_ground(t_data *data, int y, int x);
void		draw_character(int keycode, t_data *data);
int			is_and_exit(t_data *data, int y, int x);
int			get_line_len(char *str);

// Moves
int			keyhook(int keycode, t_data *data);

// read_data_from_map
char		**create_map(int fd, t_data *data);
void		map_stats(t_data *data);
char		*join_map_line(char *s1, char *s2);
void		read_map_from_file(int fd, t_data *data);

// init
void		init_game(t_data *data);
void		game(t_data *data);
void		set_img(t_data *data);
void		set_item(t_data *data, t_pos pos);
void		init_img(t_data *data);

#endif