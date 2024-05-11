/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:32:18 by robhak            #+#    #+#             */
/*   Updated: 2024/05/11 11:34:22 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

/*
 * Performs a series of checks on the map to ensure it is valid.
 * Returns 1 if the map is valid, 0 otherwise.
 */
int	map_error_checks(t_data *data, int len)
{
	if (!char_error(data))
	{
		ft_printf("Error Invalid character on map\n");
		return (0);
	}
	if (!is_rectangle(data, len) || !entity_error(data))
		return (0);
	if (!wall_error(data, len))
	{
		ft_printf("Error map not closed\n");
		return (0);
	}
	initialize_map_data(data);
	if (is_path_valid(data) == 0)
	{
		ft_printf("Error no valid path in map\n");
		return (0);
	}
	if (is_map_solvable(data) == 0)
	{
		ft_printf("Error: Map is unsolvable\n");
		return (0);
	}
	return (1);
}

/*
 * Checks if the map is not empty and then performs a
   series of checks on the map to ensure it is valid.
 * Returns 1 if the map is valid, 0 otherwise.
 */
int	map_error(t_data *data)
{
	int	len;

	if (data->map == NULL)
	{
		ft_printf("Error: Map is empty\n");
		return (0);
	}
	len = get_line_len(data->map[0]) - 1;
	return (map_error_checks(data, len));
}
