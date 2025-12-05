/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:33:54 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/05 11:38:57 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*static void fill_line(int *ints, char *str)
{
	int		i;
	char	**strs;

	strs = ft_split(str, ' ');
	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		ints[i] = ft_atoi(strs[i]);
		++i;
	}
	freeall_strs(strs);
}

static int **strstointss(char **strs)
{
	int **intss;
	int i;

	intss = ft_calloc(sizeof(int *), ft_strslen(strs) + 1);
	if (!intss)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		intss[i] = ft_calloc(sizeof(int), ft_wordcount(strs[i]));
		if (!intss[i])
		{
			freeall_intss(intss);
			return (NULL);
		}
		fill_line(intss[i], strs[i]);
		++i;
	}
	freeall_strs(strs);
	return (intss);
}*/

static void fill_points(t_point *points, char *str, int y)
{
	int		i;
	char	**strs;
	char 	**strs2;

	strs = ft_split(str, ' ');
	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		strs2 = ft_split(strs[i], ',');
		if (!strs2)
			return ;
		if (ft_strslen(strs2) > 1)
			(points[i]).color = ft_atoi(strs2[1]);
		else
			(points[i]).color = 0xFFFFFFFF;
		points[i].x = i;
		points[i].y = y;
		points[i].z = ft_atoi(strs2[0]);
		++i;
	}
	freeall_2strs(strs, strs2);
}

static int **strstopoints(char **strs)
{
	t_point *points;
	int i;

	points = ft_calloc(sizeof(t_point), ft_strslen(strs) + 1);
	if (!points)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		fill_points(points[i], strs[i], i);
		++i;
	}
	freeall_strs(strs);
	return (intss);
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

int **parse(const char *map, t_sizemap *size)
{
	char	**strs;
	int		fd;
	int		nb;
	t_point *points;

	nb = nb_line(map);
	strs = ft_calloc(sizeof(char *), nb + 1);
	if (!strs)
		return (NULL);
	fd = open (map, O_RDONLY);
	nb = 0;
	strs[0] = get_next_line(fd);
	if (!strs[0])
		return (NULL);
	while (strs[nb])
	{
		++nb;
		strs[nb] = get_next_line(fd);
	}
	nb = size_xy(strs, size);
	if (nb == 1)
		points = strstopoints(strs);
	else
		points = NULL;
	return (points);
}
