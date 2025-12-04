/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:15:44 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/04 17:21:04 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void key_hook(int key, void* param)
{
	ft_printf("%d", key);
    if(key == 41)
        mlx_loop_end((mlx_context)param);
}
