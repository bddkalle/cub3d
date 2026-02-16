/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:35 by vboxuser          #+#    #+#             */
/*   Updated: 2026/02/16 19:41:27 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_point	screen_mapping(t_vars *vars, double x, double y)
{
	double	a;
	double	b;
	double	c;
	t_point	mapped_p;

	a = (double)vars->map.pixel_per_grid / BLOCK;
	b = WIDTH - (vars->map.g_w * vars->map.pixel_per_grid);
	c = HEIGHT - (vars->map.g_h * vars->map.pixel_per_grid);
	mapped_p.px_x = a * x + b;
	mapped_p.px_y = a * y + c;
	return (mapped_p);
}

void	draw_ray(t_vars *vars, t_fpoint touchpoint)
{
	t_point	mapped_player_pos;
	t_point	mapped_touchpoint;

	mapped_player_pos = screen_mapping(vars, vars->player.x, vars->player.y);
	mapped_touchpoint = screen_mapping(vars, touchpoint.x, touchpoint.y);
	//////////
	//mapped_player_pos.px_x = (int)vars->player.x;
	//mapped_player_pos.px_y = (int)vars->player.y;
	//mapped_touchpoint.px_x = (int)touchpoint.x;
	//mapped_touchpoint.px_y = (int)touchpoint.y;
	//printf("mapped_player: (%lu, %lu)\nmapped_touchpoint: (%lu, %lu)\n", mapped_player_pos.px_x, mapped_player_pos.px_y, mapped_touchpoint.px_x, mapped_touchpoint.px_y);
	draw_line(vars, mapped_player_pos, mapped_touchpoint, 0xFF0000);
}
/*
void	draw_ray(t_vars *vars, double ray_x, double ray_y)
{
	t_point	mapped_p;

	mapped_p = screen_mapping(vars, ray_x, ray_y);
	put_pixel(vars,\
		mapped_p.px_x, mapped_p.px_y, 0xFF0000);

}*/

void	draw_player(t_vars *vars)
{
	t_point	mapped_player;

	mapped_player = screen_mapping(vars, vars->player.x, vars->player.y);
	draw_square(vars,\
		mapped_player.px_x,\
		mapped_player.px_y,\
		vars->map.pixel_per_grid / 4,
		0x00FF00);
}

void	draw_map(t_vars *vars)
{
	t_size	y;
	t_size	x;

	vars->map.pixel_per_grid = HEIGHT / (4 * vars->map.g_h);
	y = 0;
	while (y < vars->map.g_h)
	{
		x = 0;
		while (x < vars->map.g_w)
		{
			if (vars->map.grid[y][x] == '1')
				draw_square(vars,\
					WIDTH - (vars->map.g_w - x) * vars->map.pixel_per_grid,\
					HEIGHT - (vars->map.g_h - y) * vars->map.pixel_per_grid,\
					vars->map.pixel_per_grid, 0x0000FF);
			x++;
		}
		y++;
	}
	draw_player(vars);
}
