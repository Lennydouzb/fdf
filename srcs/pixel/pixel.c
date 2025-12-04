/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:26:43 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/04 17:31:29 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void coordinates(int **ints, int *x, int *y)
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
	*x += 600;
	*y += 300;
}

void	place_color(t_mlx *mlx, int **ints, int line_size)
{
	int	i;
	int	k;
	int	x;
	int y;	

	i = 0;
	while (ints[i])
	{
		k = 0;
		while (k < line_size)
		{
			x = k;
			y = i;
			coordinates(ints, &x, &y);
			mlx_set_image_pixel(mlx->mlx, mlx->img, x, y, (mlx_color){.rgba = 0xFFFFFFFF});
			++k;
		}
		++i;
	}
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
