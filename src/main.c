/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robhak <robhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:30:49 by robhak            #+#    #+#             */
/*   Updated: 2024/02/14 15:46:22 by robhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

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
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\nFile opening failed\n", 2);
		return (1);
	}
	if (create_map(&data, fd) == 1)
	{
		ft_putendl_fd("Error\nMap parsing failed\n", 2);
		free_map(&data);
		return (1);
	}
	create_game(&data);
	return (0);
}
