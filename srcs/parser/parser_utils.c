/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:21:14 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/03 15:13:48 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/fdf.h"

int	nb_line(const char *map)
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

void    freeall_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}

void    freeall_intss(int **intss)
{
	int	i;

	i = 0;
	while (intss[i])
	{
		free(intss[i]);
		++i;
	}
	free(intss);
}
