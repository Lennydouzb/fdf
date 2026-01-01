/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:33:54 by ldesboui          #+#    #+#             */
/*   Updated: 2026/01/01 12:10:17 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	create_point(t_point *points, int i, int y, char **strs2)
{
	if (ft_strslen(strs2) > 1)
		(*points).color.rgba = ft_atoi_hex(strs2[1]);
	else
		(*points).color.rgba = 0xFFFFFFFF;
	(*points).x = i;
	(*points).y = y;
	(*points).z = ft_atoi(strs2[0]);
}

static void	fill_points(t_point *points, char *str, int y, t_sizemap *size)
{
	int		i;
	char	**strs;
	char	**strs2;

	strs = ft_split(str, ' ');
	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		strs2 = ft_split(strs[i], ',');
		if (!strs2)
		{
			freeall_strs(strs);
			return ;
		}
		create_point(&points[i + y * size->size_x], i, y, strs2);
		++i;
		freeall_strs(strs2);
	}
	freeall_strs(strs);
}

static t_point	*strstopoints(char **strs, t_sizemap *size)
{
	t_point	*points;
	int		i;

	points = ft_calloc(sizeof(t_point), (size->size_x * size->size_y) + 1);
	if (!points)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		fill_points(points, strs[i], i, size);
		++i;
	}
	return (points);
}

static int	size_xy(char **strs, t_sizemap *size)
{
	int		i;
	int		tmp_size;

	tmp_size = ft_wordcount(strs[0]);
	i = 1;
	while (strs[i])
	{
		if (tmp_size != ft_wordcount(strs[i]))
			return (0);
		++i;
	}
	size->size_x = tmp_size;
	size->size_y = i;
	return (1);
}

t_point	*parse(const char *map, t_sizemap *size)
{
	char	**strs;
	int		fd;
	int		nb;
	t_point	*points;

	nb = nb_line(map);
	strs = ft_calloc(sizeof(char *), nb + 1);
	if (!strs)
		return (NULL);
	fd = open (map, O_RDONLY);
	strs[0] = get_next_line(fd);
	if (fd < 0 || !strs[0])
		freestrs_close(fd, strs);
	nb = 0;
	while (strs[nb])
		strs[++nb] = get_next_line(fd);
	nb = size_xy(strs, size);
	if (nb == 1)
		points = strstopoints(strs, size);
	else
		points = NULL;
	freeall_strs(strs);
	close(fd);
	return (points);
}
