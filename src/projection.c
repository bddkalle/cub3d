/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:23:26 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/23 16:06:19 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

double	distance(double dx, double dy)
{
	return (sqrt(dx * dx + dy * dy));
}

// draw verital line, scale obstacle by distance, correct distance to avoid fisheye distortion
// fisheye correction: 1. angular distance of alpha and beta 2. triangle: cos(beta - alpha) * dist_dist = corr_dist
// calculated projected height h of Wall with real height BLOCK: using tan(FOV/2) = 1/2 * WIDTH / distanceToProjectionScreen

double	correct_distance(t_vars *vars, double dist_d, double beta)
{
	return (dist_d * cos(beta - vars->player.alpha));
}

void	wall_projection(t_touch *slice)
{
	slice->wall_height = (BLOCK / slice->distance) * \
	(WIDTH / 2.0) / tan(PI / 6);
	slice->wall_top = (HEIGHT - slice->wall_height) / 2;
	slice->wall_bottom = slice->wall_top + slice->wall_height;
}
