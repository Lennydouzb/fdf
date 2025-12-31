/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:14:40 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/31 17:27:53 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	x_axis(int key, void *param, t_all *all)
{
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
}

static void	y_axis(int key, void *param, t_all *all)
{
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
}

static void	z_axis(int key, void *param, t_all *all)
{
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
}

void	rotations(int key, void *param, t_all *all)
{
	x_axis(key, param, all);
	y_axis(key, param, all);
	z_axis(key, param, all);
}
