/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:30:49 by robhak            #+#    #+#             */
/*   Updated: 2024/02/18 13:53:14 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\nFile opening failed\n", 2);
		return (-1);
	}
	return (fd);
}

int	validate_input(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	if (is_ber_file(av[1]) == 0)
	{
		ft_putendl_fd("Error\nInvalid file extension\n", 2);
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
	if (create_map(&data, fd) == 1)
	{
		ft_putendl_fd("Error\nMap parsing failed\n", 2);
		free_map(&data);
		return (1);
	}
	create_game(&data);
	return (0);
}
