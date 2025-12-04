/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:15:44 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/04 21:36:03 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void key_hook(int key, void* param)
{
    if  (key == 41)
        mlx_loop_end((mlx_context)param);    
}

void win_hook(int event, void* param)
{
    if (event == 0)
        mlx_loop_end((mlx_context)param);    
}