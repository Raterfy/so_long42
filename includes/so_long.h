/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:18:00 by robhak            #+#    #+#             */
/*   Updated: 2024/02/24 12:24:41 by robhak           ###   ########.fr       */
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

typedef struct bfsdata
{
	char	**map;
	int		*reachable_targets;
	int		total_targets;
	int		map_height;
	int		map_width;
}			t_bfsdata;

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
void		free_bfs_data(t_bfsdata *bfsdata);
void		free_map2(char **map, int height);
void		free_map(t_data *data);
void		free_img(t_data *data);
int			close_game(t_data *data);

// Create map
void		update_map_stats(t_data *data, int y, int x);
void		map_stats(t_data *data);
char		*join_map_line(char *s1, char *s2);
void		read_map_from_file(int fd, t_data *data);
char		**create_map(int fd, t_data *data);

// Init
void		init_img(t_data *data);
void		set_item(t_data *data, t_pos pos);
void		set_img(t_data *data);
void		game(t_data *data);
void		init_game(t_data *data);

// Is_there_valid_path
int			is_map_solvable(t_data *data);
int			is_path_valid(t_data *data);
char		*copy_map_line(char *src, int width);
char		**copy_map(t_data *data);
void		initialize_map_dimensions(t_data *data);
void		bfs(int x, int y, t_bfsdata *data);
t_bfsdata	*init_bfs_data(t_data *data);
void		initialize_map_data(t_data *data);
void		floodfill(int w, int l, char **map);
void		findplayer(int *pos, char **map);
int			check_path(t_data *data, char **copy);

// Main
int			open_file(const char *filename);
int			validate_input(int ac, char **av);
int			main(int ac, char **av);

// Move
int			keyhook(int keycode, t_data *data);
void		move_w(int keycode, t_data *data);
void		move_s(int keycode, t_data *data);
void		move_d(int keycode, t_data *data);
void		move_a(int keycode, t_data *data);

// Parsing
int			map_error(t_data *data);
int			map_error_checks(t_data *data, int len);
int			is_ber_file(char *argv);
int			char_error(t_data *data);
int			is_rectangle(t_data *data, int len);
int			entity_error(t_data *data);
int			wall_error(t_data *data, int len);

// Utils

int			get_line_len(char *str);
int			is_and_exit(t_data *data, int y, int x);
void		check_item(t_data *data, int y, int x);
void		set_ground(t_data *data, int y, int x);
void		draw_character(int keycode, t_data *data);

#endif