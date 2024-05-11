/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_there_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:52:24 by robhak            #+#    #+#             */
/*   Updated: 2024/04/09 14:29:59 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

/*
 * Checks if all collectibles in the map are reachable from 
 * the player's position.
 */
int	is_map_solvable(t_data *data)
{
	t_bfsdata	*bfsdata;
	int			result;

	initialize_map_dimensions(data);
	bfsdata = init_bfs_data(data);
	if (!bfsdata)
		return (0);
	bfs(data->player_pos_x, data->player_pos_y, bfsdata);
	result = (*bfsdata->reachable_targets == bfsdata->total_targets);
	free_bfs_data(bfsdata);
	return (result);
}

/*
 * Checks if a valid path exists from the player 
 * to all collectibles and the exit.
 */
int	is_path_valid(t_data *data)
{
	int		pos[2];
	char	**copy;

	initialize_map_data(data);
	copy = copy_map(data);
	if (!copy)
		return (0);
	findplayer(pos, copy);
	floodfill(pos[0], pos[1], copy);
	return (check_path(data, copy));
}
