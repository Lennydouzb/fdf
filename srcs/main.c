/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:40 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/08 11:24:39 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_points(t_point *points, t_sizemap size)
{
	int	i;

	i = 0;
	while (i < size.size_x * size.size_y)
	{
		ft_printf("Point %d : x = %d, y = %d, z = %d, screen_x = %d, screen_y = %d, color = %d\n", i, points[i].x, points[i].y, points[i].z, points[i].screen_x, points[i].screen_y, points[i].color);
		++i;
	}
}

int	main(void)
{
	t_mlx		*mlx;
	t_point		*points;
	t_sizemap	size;

	mlx = initialize();
	if (!mlx)
		return (1);
	points = parse("maps/test_maps/42.fdf", &size);
	if (!points)
		return (1);
	place_color(mlx, points, &size);
	print_points(points, size);
    mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx->mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, win_hook, mlx->mlx);

	mlx_loop(mlx->mlx);
	//mlx_destroy_window(mlx->mlx, mlx->win);
    //mlx_destroy_context(mlx->mlx);
}

