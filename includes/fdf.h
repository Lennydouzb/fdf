/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:39:07 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/02 19:32:41 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include "../srcs/libft/libft.h"
# include "../srcs/printf/ft_printf.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buffer;
}	t_mlx;
char	*get_next_line(int fd);


void parse(const char *map);

#endif
