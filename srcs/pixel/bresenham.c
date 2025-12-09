/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:59:34 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/09 13:42:52 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	absol(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}
static void	trace(int fstx, int fsty, int sndx, int sndy, t_mlx *mlx)
{
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
	int	e2;
	
	dx = absol(sndx - fstx);
	dy = absol(sndy - fsty);
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
		if (fstx >= 0 && fstx < 1920 && fsty >= 0 && fsty < 1080)
		{
			mlx_set_image_pixel(mlx->mlx, mlx->img, fstx, fsty, (mlx_color){.rgba = 0xFFFFFFFF});
		}
		if (fstx == sndx && fsty == sndy)
			return ;
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
