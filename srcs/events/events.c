/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:15:44 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/10 18:22:52 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end((mlx_context)param);
}

static void	win_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}

void	event_loop(t_mlx *mlx)
{
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, key_hook, mlx->mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, win_hook, mlx->mlx);
	mlx_loop(mlx->mlx);
}
