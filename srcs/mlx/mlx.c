/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:35:39 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/04 17:30:58 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_mlx	*initialize()
{
	t_mlx *mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (NULL);
	mlx->info.title = "FdF";
	mlx->info.width = 1920;
	mlx->info.height = 1080;
	mlx->win = mlx_new_window(mlx->mlx, &(mlx->info));
	mlx->img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->img_info.render_target = mlx->img;
	mlx->img_win = mlx_new_window(mlx->mlx, &(mlx->img_info));
	return (mlx);
}
