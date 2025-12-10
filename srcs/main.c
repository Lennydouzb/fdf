/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:40 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/10 16:33:52 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_mlx		*mlx;
	t_point		*points;
	t_sizemap	size;

	if (ac == 2)
	{
		points = parse(av[1], &size);
		if (!points)
		{
			write (2, "Error on point parsing, arg file might not exist\n", 49);
			return (1);
		}
		mlx = initialize();
		if (!mlx)
		{
			write (2, "Error while creating mlx\n", 25);
			free(points);
			return (1);
		}
		place_color(mlx, points, &size);
		free(points);
		loop_and_destroy_mlx(mlx);
		return (0);
	}
	write (2, "No .fdf file passed in args, or multiple args\n", 46);
}
