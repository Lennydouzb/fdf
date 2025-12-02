/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:40 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/02 19:14:57 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	t_mlx	mlx;
	int		bpp;
	int		line_len;
	int		endian;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (0);
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "FdF");
	mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
	mlx.buffer = mlx_get_data_addr(mlx.img, &bpp, &line_len, &endian);
	parse(mlx.buffer, "maps/test_maps/42.fdf");
	ft_printf("%s", mlx.buffer);
	mlx_loop(mlx.mlx);
}

