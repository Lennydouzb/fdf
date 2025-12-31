/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:09:06 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/31 17:25:00 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	zoom(int key, void *param, t_all *all)
{
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
}

static void	addoffset(int key, void *param, t_all *all)
{
	if (key == 81)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->offsety += 1;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 79)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->offsetx += 1;
		place_color(all->mlx, all->points, all->size);
	}
}

static void	rmoffset(int key, void *param, t_all *all)
{
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
}

void	movements(int key, void *param, t_all *all)
{
	zoom(key, param, all);
	rmoffset(key, param, all);
	addoffset(key, param, all);
}
