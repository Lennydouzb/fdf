/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:15:44 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/01 12:20:59 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	key_hook(int key, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key == 41)
	{
		mlx_loop_end(all->mlx->mlx);
	}
	movements(key, param, all);
	iso(key, param, all);
	rotations(key, param, all);
}

static void	win_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void	event_loop(t_mlx *mlx, t_point *points, t_sizemap *size)
{
	t_all	*all;

	all = ft_calloc(sizeof(t_all), 1);
	if (!all)
		return ;
	all->mlx = mlx;
	all->points = points;
	all->size = size;
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, all);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, win_hook, mlx->mlx);
	mlx_loop(mlx->mlx);
	free(all);
}
