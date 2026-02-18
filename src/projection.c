/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:23:26 by fschnorr          #+#    #+#             */
/*   Updated: 2026/02/18 09:51:59 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

double	distance(double dx, double dy)
{
	return (sqrt(dx * dx + dy * dy));
}

/*
fisheye correction:
1. angular distance of alpha and beta
2. triangle: cos(beta - alpha) * dist_dist = corr_dist
*/

double	correct_distance(t_vars *vars, double dist_d, double beta)
{
	return (dist_d * cos(beta - vars->player.alpha));
}

/*
calculating projected height h of Wall with real height BLOCK:
using tan(FOV/2) = 1/2 * WIDTH / distanceToProjectionScreen
*/

void	wall_projection(t_intrsec *slice)
{
	slice->wall_height = (BLOCK / slice->distance) * \
	(WIDTH / 2.0) / tan(PI / 6);
	slice->wall_top = (HEIGHT - slice->wall_height) / 2;
	slice->wall_bottom = slice->wall_top + slice->wall_height;
}
