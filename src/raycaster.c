/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:24:48 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/22 14:07:11 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/* wall orientation is determined by rounding down ray coordinates and check whether grid=1 is touched.
For edge cases it is necessary to check wether angle is left/right or up/down & check if neighboring grid is wall*/
//&& cos(beta) >= 0
//&& cos(beta) < 0 &&
//&& sin(beta) >= 0
//&& sin(beta) < 0
//&& vars->player.x < px
//&& vars->player.x > px
//&& vars->player.y < py
//&& vars->player.y > py

void	wall_orientation(t_vars *vars, t_touch *wall_slice, float px, float py, float beta)
{
	(void)beta;
	if ((int)px % BLOCK == 0)
	{
		wall_slice->txt = &vars->map.we;
		wall_slice->offset = (int)py % BLOCK;
	}
	else if ((int)px % BLOCK == BLOCK - 1)
	{
		wall_slice->txt = &vars->map.ea;
		wall_slice->offset = BLOCK - 1 - (int)py % BLOCK;
	}
	else if ((int)py % BLOCK == 0)
	{
		wall_slice->txt = &vars->map.no;
		wall_slice->offset = BLOCK - 1 - (int)px % BLOCK;
	}
	else if ((int)py % BLOCK == BLOCK - 1)
	{
		wall_slice->txt = &vars->map.so;
		wall_slice->offset = (int)px % BLOCK;
	}
}

void	wall_info(t_vars *vars, t_touch *wall_slice, float px, float py, float beta)
{
	wall_orientation(vars, wall_slice, px, py, beta);
	wall_slice->distance = correct_distance(
			vars,\
			distance(\
				px - vars->player.x,\
				py - vars->player.y),\
			beta);
	wall_projection(wall_slice);
}

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
	float	ray_x;
	float	ray_y;
	float	cos_beta;
	float	sin_beta;
	t_touch	wall_slice;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	cos_beta = cos(beta);
	sin_beta = sin(beta);
	wall_slice.touch = touch(vars, ray_x, ray_y);
	while (wall_slice.touch == NOTOUCH)
	{
		if (draw_map)
			draw_ray(vars, ray_x, ray_y);
		ray_x += cos_beta;
		ray_y += sin_beta;
		wall_slice.touch = touch(vars, ray_x, ray_y);
	}
	if (wall_slice.touch == UNDET)
	{
		printf("touch undet.\n");
		return ;
	}
	wall_info(vars, &wall_slice, ray_x, ray_y, beta);
	draw_vertical_line(vars, ray_id, &wall_slice, draw_map);
}
