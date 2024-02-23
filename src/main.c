/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:30:49 by robhak            #+#    #+#             */
/*   Updated: 2024/02/23 19:25:34 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error File opening failed", 2);
		return (-1);
	}
	return (fd);
}

int	validate_input(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Error Invalid number of arguments", 2);
		return (1);
	}
	if (is_ber_file(av[1]) == 0)
	{
		ft_putendl_fd("Error Invalid file extension", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (validate_input(ac, av) == 1)
		return (1);
	fd = open_file(av[1]);
	if (fd == -1)
		return (1);
	if (!create_map(fd, &data))
	{
		free_map(&data);
		return (1);
	}
	if (data.map == NULL)
	{
		ft_putendl_fd("Error: Map is empty", 2);
		free_map(&data);
		return (1);
	}
	init_game(&data);
	return (0);
}
