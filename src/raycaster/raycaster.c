/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:24:48 by fschnorr          #+#    #+#             */
/*   Updated: 2026/02/17 17:25:12 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	wall_info(t_vars *vars, t_intrsec *wall_slice, double beta)
{
	wall_slice->distance = correct_distance(vars, wall_slice->distance, beta);
	wall_orientation(vars, wall_slice);
	wall_projection(wall_slice);
}

void	cast_ray(t_vars *vars, double beta, int ray_id, bool draw_map)
{
	t_intrsec	wall_slice_hor;
	t_intrsec	wall_slice_ver;

	first_horizontal_intersec(vars, &wall_slice_hor, beta);
	first_vertical_intersec(vars, &wall_slice_ver, beta);
	while (wall_slice_hor.touch == NOTOUCH)
		next_horizontal_intersec(vars, &wall_slice_hor, beta);
	while (wall_slice_ver.touch == NOTOUCH)
		next_vertical_intersec(vars, &wall_slice_ver, beta);
	if (wall_slice_ver.distance < wall_slice_hor.distance\
		&& wall_slice_ver.touch == TOUCH)
	{
		wall_info(vars, &wall_slice_ver, beta);
		draw_column(vars, ray_id, &wall_slice_ver, draw_map);
		if (draw_map)
			draw_ray(vars, wall_slice_ver.touchpoint);
	}
	else if (wall_slice_ver.distance > wall_slice_hor.distance\
		&& wall_slice_hor.touch == TOUCH)
	{
		wall_info(vars, &wall_slice_hor, beta);
		draw_column(vars, ray_id, &wall_slice_hor, draw_map);
		if (draw_map)
			draw_ray(vars, wall_slice_hor.touchpoint);
	}
}
