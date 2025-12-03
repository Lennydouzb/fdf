/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:21:14 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/03 10:21:14 by ldesboui         ###   ########.fr       */
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

void    freeall(char **strs)
{
	int	i;

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

	while (intss[i])
	{
		free(intss[i]);
		++i;
	}
	free(intss);
}