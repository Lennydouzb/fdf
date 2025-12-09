/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:32:37 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/09 13:32:37 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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