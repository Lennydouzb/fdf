/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:21:41 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/01 17:10:24 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/fdf.h"

void	iso(int key, void *param, t_all *all)
{
	if (key == 38)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->iso += 0.05;
		place_color(all->mlx, all->points, all->size);
	}
	if (key == 30)
	{
		all = (t_all *)param;
		reset_image(all->mlx);
		all->mlx->iso = 0.0;
		all->mlx->angle_x = 0.0;
		all->mlx->angle_y = 0.0;
		all->mlx->angle_z = 0.0;
		place_color(all->mlx, all->points, all->size);
	}
}
