/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:39:07 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/03 11:01:03 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include "../srcs/libft/libft.h"
# include "../srcs/printf/ft_printf.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buffer;
}	t_mlx;

# define ISO 0.523599
char	*get_next_line(int fd);
int		nb_line(const char *map);
void 	freeall(char **strs);
void	freeall_intss(int **intss);
int		**parse(const char *map);

#endif
