/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:39:07 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/05 15:55:18 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef ISO
#	define ISO 0.523599
# endif
# ifndef ZOOM
#  define ZOOM 30
# endif

# include "../MacroLibX/includes/mlx.h"
# include <fcntl.h>
# include <math.h>
# include "../srcs/libft/libft.h"
# include "../srcs/printf/ft_printf.h"

typedef struct	s_mlx
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
	mlx_image				img;
	mlx_window				img_win;
	mlx_window_create_info	img_info;
}	t_mlx;

typedef struct s_sizemap
{
	int	size_x;
	int	size_y;
}	t_sizemap;

typedef struct s_point
{
	int	x;
	int	y;
	int	screen_x;
	int	screen_y;
	int	z;
	int	color;
}	t_point;

char	*get_next_line(int fd);
int		nb_line(const char *map);
void 	freeall_strs(char **strs);
void	freeall_intss(int **intss);
t_point	*parse(const char *map, t_sizemap *size);
void	place_color(t_mlx *mlx, t_point *points, t_sizemap *size);
t_mlx	*initialize();
void	key_hook(int key, void* param);
void	win_hook(int event, void* param);

#endif
