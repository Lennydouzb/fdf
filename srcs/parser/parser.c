/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:33:54 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/03 11:04:28 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void fill_line(int *ints, char *str)
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
}

static int **strstointss(char **strs)
{
	int **intss;
	int i;

	intss = ft_calloc(sizeof(int *), ft_strslen(strs));
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
	}
	freeall(strs);
	return (intss);
}

int **parse(const char *map)
{
	char	**strs;
	int		fd;
	int		nb;
	int		**intss;

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
		if (!strs[nb])
		{
			freeall(strs);
			return (NULL);
		}
	}
	intss = strstointss(strs);
	return (intss);
}
