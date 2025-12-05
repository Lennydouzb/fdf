/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:26:43 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/05 11:48:56 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void coordinates(int **ints, int *x, int *y, t_sizemap *size)
{
	int	basex;
	int	basey;
	int	tmp_zoomedx;

	basex = *x;
	basey = *y;
	*x *= ZOOM;
	tmp_zoomedx = *x;
	*y *= ZOOM;
	*x = (*x - *y) * cos(ISO);
	*y = ((tmp_zoomedx + *y) * sin(ISO)) - (ints[basey][basex] * ZOOM);
	*x = *x - (size->size_x / 2) + 1920 / 2;
	*y = *y - (size->size_y / 2) + 1080 / 2;
}

/*void	place_color(t_mlx *mlx, int **ints, t_sizemap *size)
{
	int	i;
	int	k;
	int	x;
	int y;	

	i = 0;
	while (i < size->size_y)
	{
		k = 0;
		while (k < size->size_x)
		{
			x = k;
			y = i;
			coordinates(ints, &x, &y, size);
			mlx_set_image_pixel(mlx->mlx, mlx->img, x, y, (mlx_color){.rgba = 0xFFFFFFFF});
			++k;
		}
		++i;
	}
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}*/

/*void	place_color(t_mlx *mlx, int **ints, t_sizemap *size)
{
	int	i;
	int	k;
	int	x;
	int y;	

	i = 0;
	while (i < size->size_y)
	{
		k = 0;
		while (k < size->size_x)
		{
			x = k;
			y = i;
			coordinates(ints, &x, &y, size);
			mlx_set_image_pixel(mlx->mlx, mlx->img, x, y, (mlx_color){.rgba = 0xFFFFFFFF});
			++k;
		}
		++i;
	}
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}*/


void	place_color(t_mlx *mlx, t_points *points, t_sizemap *size)
{
	int	i;

	i = 0;
	while (points[i])
	{
		coordinates(points[k], size);
		mlx_set_image_pixel(mlx->mlx, mlx->img, points->screen_x, points->screen_y, (mlx_color){.rgba = 0xFFFFFFFF});
	}
	++i;
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}