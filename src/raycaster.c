/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:24:48 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/23 09:35:10 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_wall	touch(t_vars *vars, float px, float py)
{
	int	x;
	int	y;

	x = (int)px / BLOCK;
	y = (int)py / BLOCK;
	if (x < 0 || y <0 || (t_size)y >= vars->map.g_h || (t_size)x >= vars->map.g_w)
		return (UNDET);
	if (vars->map.grid[y][x] == '1')
		return (TOUCH);
	else
		return (NOTOUCH);
}

void	draw_vertical_line(t_vars *vars, int ray_id, t_touch *wall_slice, bool draw_map)
{
	int		y;
	int		color;

	y = HEIGHT - 1;
	while (y >= 0)
	{
		if (draw_map\
			&& (t_size)ray_id >= WIDTH - (vars->map.g_w * vars->map.pixel_per_grid)\
			&& (t_size)y >= HEIGHT - (vars->map.g_h * vars->map.pixel_per_grid))
			y--;
		else if (y > wall_slice->wall_bottom)
			put_pixel(vars, ray_id, y--, create_argb(vars->map.floor));
		else if (y > wall_slice->wall_top)
		{
			color = get_color_from_txt(vars, wall_slice, y);
			put_pixel(vars, ray_id, y--, color);
		}
		else
			put_pixel(vars, ray_id, y--, create_argb(vars->map.ceiling));
	}
}

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
		wall_info2(vars, &wall_slice_ver, beta);
		//printf("Player (%f, %f), TP Vertical (%f, %f)\n", vars->player.x, vars->player.y, wall_slice_ver.touchpoint.x, wall_slice_ver.touchpoint.y);
		draw_vertical_line(vars, ray_id, &wall_slice_ver, draw_map);
	}
	else if (wall_slice_ver.distance < 0 || wall_slice_ver.distance > wall_slice_hor.distance)
	{
		wall_info2(vars, &wall_slice_hor, beta);
		//printf("Player (%f, %f), TP Horizontal (%f, %f)\n", vars->player.x, vars->player.y, wall_slice_hor.touchpoint.x, wall_slice_hor.touchpoint.y);
		draw_vertical_line(vars, ray_id, &wall_slice_hor, draw_map);
	}
}
