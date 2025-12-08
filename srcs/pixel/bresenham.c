/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:59:34 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/08 20:15:45 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
//static void trace_debug(int x0, int y0, int x1, int y1, t_mlx *mlx)
//{
//    int dx = abs(x1 - x0);
//    int dy = abs(y1 - y0);
//    int sx = (x0 < x1) ? 1 : -1;
//    int sy = (y0 < y1) ? 1 : -1;
//    int err = dx - dy;
//    int e2;
//    
//    // DEBUG COULEUR : Vert si mur (dy > dx), Rouge si plat (dx > dy)
//    int color = (dy > dx) ? 0x00FF00FF : 0xFF0000FF; 
//
//    while (1)
//    {
//        // Protection écran
//        if (x0 >= 0 && x0 < 1920 && y0 >= 0 && y0 < 1080)
//            mlx_set_image_pixel(mlx->mlx, mlx->img, x0, y0, (mlx_color){.rgba = color});
//
//        if (x0 == x1 && y0 == y1) break;
//
//        e2 = 2 * err;
//        if (e2 > -dy) { err -= dy; x0 += sx; }
//        if (e2 < dx)  { err += dx; y0 += sy; }
//    }
//}
static void	trace(int fstx, int fsty, int sndx, int sndy, t_mlx *mlx)
{
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
	int	e2;
	
	dx = ABS(sndx - fstx);
	dy = ABS(sndy - fsty);
	if (fstx < sndx)
		sx = 1;
	else
		sx = -1;
	if (fsty < sndy)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		mlx_set_image_pixel(mlx->mlx, mlx->img, fstx, fsty, (mlx_color)0xFFFFFFFF);
		if (fstx == sndx && fsty == sndy)
			break ;
		e2 = 2 *err;
		if (e2 > -dy)
		{
			err -= dy;
			fstx += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			fsty += sy;
		}
	}
}

void	bresenham(t_point *points, t_sizemap *size, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	print_points(points, size[0]);
	while (y < size->size_y)
	{
		x = 0;
		while (x < size->size_x)
		{
			if (x < size->size_x - 1)
				trace(points[x + size->size_x * y].screen_x, 
					points[x + size->size_x * y].screen_y,
					points[x + 1 + size->size_x * y].screen_x,
					points[x + 1 + size->size_x * y].screen_y, mlx);
			if (y < size->size_y - 1)
				trace(points[x + size->size_x * y].screen_x, 
					points[x + size->size_x * y].screen_y,
					points[x + size->size_x * (y + 1)].screen_x,
					points[x + size->size_x * (y + 1)].screen_y, mlx);

			++x;
		}
		++y;
	}
}
