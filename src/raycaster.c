/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:24:48 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/20 12:27:22 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/* wall orientation is determined by rounding down ray coordinates and check whether grid=1 is touched.
For edge cases it is necessary to check wether angle is left/right or up/down & check if neighboring grid is wall*/
void	wall_orientation(t_vars *vars, t_touch *wall_slice, float px, float py, float beta)
{
	if ((int)px % BLOCK == 0 && cos(beta) > 0 && !touch(vars, px - 1, py))
	{
		wall_slice->wall_orient = WEST;
		wall_slice->txt = &vars->map.we;
		wall_slice->offset = (int)py % BLOCK;
	}
	else if ((int)px % BLOCK == BLOCK - 1 && cos(beta) < 0 &&\
		!touch(vars, px + 1, py))
	{
		wall_slice->wall_orient = EAST;
		wall_slice->txt = &vars->map.ea;
		wall_slice->offset = (int)py % BLOCK;
	}
	else if ((int)py % BLOCK == 0 && sin(beta) > 0)
	{
		wall_slice->wall_orient = NORTH;
		wall_slice->txt = &vars->map.no;
		wall_slice->offset = (int)px % BLOCK;
	}
	else if ((int)py % BLOCK == BLOCK - 1 && sin(beta) < 0)
	{
		wall_slice->wall_orient = SOUTH;
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

bool	touch(t_vars *vars, float px, float py)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (vars->map.grid[y][x] == '1')
		return (true);
	else
		return (false);
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
	t_touch	wall_slice;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	while (!touch(vars, ray_x, ray_y))
	{
		if (draw_map)
			draw_ray(vars, ray_x, ray_y);
		ray_x += cos(beta);
		ray_y += sin(beta);
	}
	wall_info(vars, &wall_slice, ray_x, ray_y, beta);
	draw_vertical_line(vars, ray_id, &wall_slice, draw_map);
}
