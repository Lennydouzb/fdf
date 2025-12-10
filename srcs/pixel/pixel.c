/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:26:43 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/10 18:30:06 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void coordinates(t_point *points, t_sizemap *size)
{
	points->screen_x = points->x * ZOOM;
	points->screen_y = points->y * ZOOM;
	points->screen_x = (points->screen_x - points->screen_y) * cos(ISO);
	points->screen_y = ((points->x * ZOOM + points->y * ZOOM) * sin(ISO))
		- (points->z * ZOOM);
	points->screen_x = points->screen_x - (size->size_x / 2) + 1920 / 2;
	points->screen_y = points->screen_y - (size->size_y / 2) + 1080 / 2;
}

void	place_color(t_mlx *mlx, t_point *points, t_sizemap *size)
{
	int	i;

	i = 0;
	while (i < size->size_y * size->size_x)
	{
		coordinates(&points[i], size);
		mlx_set_image_pixel(mlx->mlx, mlx->img, points[i].screen_x,
			points[i].screen_y, points[i].color);
		++i;
	}
	bresenham(points, size, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
