/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:53:24 by ldesboui          #+#    #+#             */
/*   Updated: 2025/12/11 15:53:24 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void    rotate_x(double *y, double *z, double angle)
{
    double tmp;

    tmp = *y;
    *y = *y * cos(angle) + *z * sin(angle);
    *z = -tmp * sin(angle) + *z * cos(angle);
}

void    rotate_y(double *x, double *z, double angle)
{
    double tmp;

    tmp = *x;
    *x = *x * cos(angle) + *z * sin(angle);
    *z = -tmp * sin(angle) + *z * cos(angle);
}

void    rotate_z(double *x, double *y, double angle)
{
    double tmp;

    tmp = *x;
    *x = *x * cos(angle) + *y * sin(angle);
    *y = -tmp * sin(angle) + *y * cos(angle);
}