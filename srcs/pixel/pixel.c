/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:26:43 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/11 00:38:47 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void calc(t_point pts, t_sizemap *size, double iso, t_size_r *size_r)
{
	double	render_x;
	double	render_y;
	
	render_x = (pts.x - (size->size_x / 2)
			- pts.y - size->size_y / 2) * cos(iso);
	render_y = (pts.x - (size->size_x / 2)
		+ pts.y - size->size_y / 2) * sin(iso) - (pts.z);
	if (render_x > size_r->max_x)
		size_r->max_x = render_x;
	if (render_x < size_r->min_x)
		size_r->min_x = render_x;
	if (render_y > size_r->max_y)
		size_r->max_y = render_y;
	if (render_y < size_r->min_y)
		size_r->min_y = render_y;
}

static int	perfect_zoom(t_point *points, t_sizemap *size, double iso)
{
	t_size_r	size_render;
	int	i;
	
	i = 0;
	size_render.max_x = -2147483648;
	size_render.max_y = -2147483648;
	size_render.min_x = 2147483647;
	size_render.min_y = 2147483647;
	while (i < size->size_y * size->size_x)
	{
		calc(points[i], size, iso, &size_render);
		++i;
	}
	if ((1920 - 100) / (size_render.max_x - size_render.min_x) <
		 (1080 - 100) / (size_render.max_y - size_render.min_y))
		return ((int)(1920 - 100) / (size_render.max_x - size_render.min_x));
	else
		return ((int)(1080 - 100) / (size_render.max_y - size_render.min_y));
}

static void coordinates(t_point *points, t_sizemap *size, double iso, int zoom)
{
	double center_x;
	double center_y;

	center_x = points->x - (size->size_x / 2);
	center_y = points->y - (size->size_y / 2);
	points->screen_x = (center_x - center_y) * zoom * cos(iso) ;
	points->screen_y = (center_x + center_y) * zoom * sin(iso) - (points->z 
		* zoom);
	points->screen_x += 1920 / 2;
	points->screen_y += 1080 / 2;
}

void	place_color(t_mlx *mlx, t_point *points, t_sizemap *size)
{
	int	i;
	int	zoom;

	zoom = perfect_zoom(points, size, ISO);
	i = 0;

	while (i < size->size_y * size->size_x)
	{
		coordinates(&points[i], size, ISO, zoom);
		mlx_set_image_pixel(mlx->mlx, mlx->img, points[i].screen_x,
			points[i].screen_y, points[i].color);
		++i;
	}
	bresenham(points, size, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
