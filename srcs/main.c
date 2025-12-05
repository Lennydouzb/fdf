/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:40 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/05 11:39:50 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	t_mlx		*mlx;
	t_point		*points;
	t_sizemap	size;

	mlx = initialize();
	if (!mlx)
		return (1);
	points = parse("maps/test_maps/42.fdf", &size);
	place_color(mlx, points, &size);
    mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx->mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, win_hook, mlx->mlx);

	mlx_loop(mlx->mlx);
	//mlx_destroy_window(mlx->mlx, mlx->win);
    //mlx_destroy_context(mlx->mlx);
}

