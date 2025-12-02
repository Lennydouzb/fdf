/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:33:54 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/02 19:45:45 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	nb_line(const char *map)
{
	char	*str;
	int		fd;
	int		nb;
	
	nb = 0;
	fd = open (map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free (str);
		str = get_next_line(fd);
		++nb;
	}
	free (str);
	return (nb);
}

static void freeall(char **strs)
{
	int	i;

	while (strs[i])
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}

static int **strstointss(char **strs)
{
	int **intss;

	intss = ft_calloc(sizeof(int *), ft_strslen(strs));
	if (!intss)
		return (NULL);
	
}

void parse(const char *map)
{
	char	**str;
	int		fd;
	int		nb;

	nb = nb_line(map);
	str = ft_calloc(sizeof(char *), nb + 1);
	if (!str)
		return ;
	fd = open (map, O_RDONLY);
	nb = 0;
	str[0] = get_next_line(fd);
	if (!str[0])
		return ;
	while (str[nb])
	{
		++nb;
		str[nb] = get_next_line(fd);
		if (!str[nb])
			freeall(str);
	}
}
