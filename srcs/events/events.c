/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:15:44 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/11 19:04:56 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	key_hook(int key, void *param)
{
	t_all *all;

	if (key == 41)
	{
		all = (t_all *)param;
		mlx_loop_end(all->mlx->mlx);
	}
	if (key == 46)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->zoom += 1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 45)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->zoom += -1;
		if (all->mlx->zoom == -1)
			all->mlx->zoom = 0;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 81)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->offsety += 1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 82)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->offsety += -1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 80)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->offsetx += -1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 79)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->offsetx += 1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 38)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->iso += 0.05;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 26)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->angle_x += 0.1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 22)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->angle_x -= 0.1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 4)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->angle_y -= 0.1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 7)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->angle_y += 0.1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 20)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->angle_z -= 0.1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 8)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->angle_z += 0.1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 30)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->iso = 1.0;
		place_color(all->mlx, all->points, all->size);
	}
}

static void	win_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void	event_loop(t_mlx *mlx, t_point *points, t_sizemap *size)
{
	t_all *all;

	all = ft_calloc(sizeof(t_all), 1);
	if (!all)
		return ;
	all->mlx = mlx;
	all->points = points;
	all->size = size;
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, all);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, win_hook, mlx->mlx);
	mlx_loop(mlx->mlx);
	free(all);
}
