/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:24:48 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/23 15:50:15 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	wall_info(t_vars *vars, t_touch *wall_slice, float beta)
{
	wall_slice->distance = correct_distance(vars, wall_slice->distance, beta);
	wall_orientation(vars, wall_slice, beta);
	wall_projection(wall_slice);
}

/*
void	cast_ray(t_vars *vars, float beta, int ray_id, bool draw_map)
{
	t_touch	wall_slice_hor;
	t_touch	wall_slice_ver;

	(void)draw_map;
	touch_horizontal(vars, &wall_slice_hor, beta, ray_id);
	touch_vertical(vars, &wall_slice_ver, beta, ray_id);
	//printf("hor dist: %f, vert_dist: %f\n", wall_slice_hor.distance, wall_slice_ver.distance);
	if (wall_slice_hor.distance < 0 || wall_slice_ver.distance < wall_slice_hor.distance)
	{
		wall_info(vars, &wall_slice_ver, beta);
		//printf("Player (%f, %f), TP Vertical (%f, %f)\n", vars->player.x, vars->player.y, wall_slice_ver.touchpoint.x, wall_slice_ver.touchpoint.y);
		draw_vertical_line(vars, ray_id, &wall_slice_ver, draw_map);
	}
	else if (wall_slice_ver.distance < 0 || wall_slice_ver.distance > wall_slice_hor.distance)
	{
		wall_info(vars, &wall_slice_hor, beta);
		//printf("Player (%f, %f), TP Horizontal (%f, %f)\n", vars->player.x, vars->player.y, wall_slice_hor.touchpoint.x, wall_slice_hor.touchpoint.y);
		draw_vertical_line(vars, ray_id, &wall_slice_hor, draw_map);
	}
}*/

void	cast_ray(t_vars *vars, float beta, int ray_id, bool draw_map)
{
	t_touch	wall_slice_hor;
	t_touch	wall_slice_ver;

	first_horizontal_intersec(vars, &wall_slice_hor, beta);
	first_vertical_intersec(vars, &wall_slice_ver, beta);
	while (wall_slice_hor.touch == NOTOUCH)
		next_horizontal_intersec(vars, &wall_slice_hor, beta);
	while (wall_slice_ver.touch == NOTOUCH)
		next_vertical_intersec(vars, &wall_slice_ver, beta);
	if (wall_slice_ver.distance < wall_slice_hor.distance && wall_slice_ver.touch == TOUCH)
	{
		wall_info(vars, &wall_slice_ver, beta);
		draw_vertical_line(vars, ray_id, &wall_slice_ver, draw_map);
	}
	else if (wall_slice_ver.distance > wall_slice_hor.distance && wall_slice_hor.touch == TOUCH)
	{
		wall_info(vars, &wall_slice_hor, beta);
		draw_vertical_line(vars, ray_id, &wall_slice_hor, draw_map);
	}
}
