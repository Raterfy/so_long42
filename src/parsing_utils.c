/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:07:37 by robhak            #+#    #+#             */
/*   Updated: 2024/02/24 12:08:27 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/ft_printf.h"

int	is_ber_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i < 4)
		return (0);
	if (argv[i - 4] == '.' && argv[i - 3] == 'b' && argv[i - 2] == 'e'
		&& argv[i - 1] == 'r')
		return (1);
	return (0);
}

int	char_error(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'C' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	entity_error(t_data *data)
{
	if (data->count_p != 1)
	{
		ft_printf("Error map must have one starting position\n");
		return (0);
	}
	else if (data->count_e != 1)
	{
		ft_printf("Error map must have one exit\n");
		return (0);
	}
	else if (data->count_c < 1)
	{
		ft_printf("Error map must have one collectible or more\n");
		return (0);
	}
	return (1);
}

int	is_rectangle(t_data *data, int len)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (len != get_line_len(data->map[i]) - 1)
		{
			ft_printf("Error map must be rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	wall_error(t_data *data, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j++] != '1')
			return (0);
	}
	i++;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][len] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (data->map[i - 1][j])
	{
		if (data->map[i - 1][j++] != '1')
			return (0);
	}
	return (1);
}
