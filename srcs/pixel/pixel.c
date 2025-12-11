/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:26:43 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/11 19:03:56 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void calc(t_point pts, t_sizemap *size, double iso, t_size_r *size_r)
{
	double	render_x;
	double	render_y;
	
	render_x = ((pts.x - size->size_x / 2.0)
			- (pts.y - size->size_y / 2.0)) * cos(iso);
	render_y = ((pts.x - size->size_x / 2.0)
		+ (pts.y - size->size_y / 2)) * sin(iso) - (pts.z);
	if (render_x > size_r->max_x)
		size_r->max_x = render_x;
	if (render_x < size_r->min_x)
		size_r->min_x = render_x;
	if (render_y > size_r->max_y)
		size_r->max_y = render_y;
	if (render_y < size_r->min_y)
		size_r->min_y = render_y;
}

static int	find_zoom(t_point *pts, t_sizemap *size, 
	double iso, t_size_r *size_r)
{
	int	i;
	int	zoom_x;
	int	zoom_y;

	i = 0;
	size_r->max_x = -2147483648;
	size_r->max_y = -2147483648;
	size_r->min_x = 2147483647;
	size_r->min_y = 2147483647;
	while (i < size->size_y * size->size_x)
	{
		calc(pts[i], size, iso, size_r);
		++i;
	}
	zoom_x = (1920.0 - 300.0) / (size_r->max_x - size_r->min_x);
	zoom_y = (1080.0 - 300.0) / (size_r->max_y - size_r->min_y);
	if (zoom_x > 30)
		zoom_x = 30;
	if (zoom_y > 30)
		zoom_y = 30;
	if (zoom_x < zoom_y)
		return (zoom_x);
	return (zoom_y);
}

static void coordinates(t_point *points, t_sizemap *size, t_mlx *mlx)
{
	double center_x;
	double center_y;
	double double_z;

	double_z = (double)points->z;
	center_x = points->x - (size->size_x / 2);
	center_y = points->y - (size->size_y / 2);
	rotate_x(&center_y, &double_z, mlx->angle_x);
	rotate_y(&center_x, &double_z, mlx->angle_y);
	rotate_z(&center_x, &center_y, mlx->angle_z);
	points->screen_x = (center_x - center_y) * mlx->zoom * cos(mlx->iso) ;
	points->screen_y = (center_x + center_y) * mlx->zoom * sin(mlx->iso) - (double_z 
		* mlx->zoom);
	points->screen_x += mlx->offsetx;
	points->screen_y += mlx->offsety;
}

void	place_color(t_mlx *mlx, t_point *points, t_sizemap *size)
{
	int			i;
	t_size_r 	limits;
	
	if (mlx->iso == 0)
		mlx->iso = ISO;
	if (mlx->zoom == -1)
		mlx->zoom = find_zoom(points, size, mlx->iso, &limits);
	if (mlx->offsetx == 0)
		mlx->offsetx = 1920 / 2 -((limits.max_x + limits.min_x)) * mlx->zoom / 2;
	if (mlx->offsety == 0)
		mlx->offsety = 1080 / 2 - ((limits.max_y + limits.min_y)) * mlx->zoom / 2;
	i = 0;
	if (mlx->zoom == 0)
		mlx->zoom = 1;
	while (i < size->size_y * size->size_x)
	{
		coordinates(&points[i], size, mlx);
		mlx_set_image_pixel(mlx->mlx, mlx->img, points[i].screen_x,
			points[i].screen_y, points[i].color);
		++i;
	}
	bresenham(points, size, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}