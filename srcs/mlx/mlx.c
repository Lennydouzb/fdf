/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:35:39 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/11 16:34:59 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_mlx	*initialize(void)
{
	t_mlx	*mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		free(mlx);
		return (NULL);
	}
	mlx->info.title = "FdF";
	mlx->info.width = 1920;
	mlx->info.height = 1080;
	mlx->win = mlx_new_window(mlx->mlx, &(mlx->info));
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->img_info.render_target = mlx->img;
	mlx->offsetx = 0;
	mlx->offsety = 0;
	mlx->iso = 0;
	mlx->zoom = 0;
	mlx->angle_x = 0;
	mlx->angle_y = 0;
	mlx->angle_z = 0;
	mlx->projection_mode = 0;
	return (mlx);
}

void	loop_and_destroy_mlx(t_mlx *mlx, t_point *points, t_sizemap *size)
{
	event_loop(mlx, points, size);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
	free(mlx);
}

void	reset_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->img_info.render_target = mlx->img;
}