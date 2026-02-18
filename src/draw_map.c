/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:35 by vboxuser          #+#    #+#             */
/*   Updated: 2026/02/18 16:03:17 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_point	screen_mapping(t_vars *vars, double x, double y)
{
	double	a;
	double	b;
	double	c;
	t_point	mapped_p;

	a = (double)vars->map.ppg / BLOCK;
	b = WIDTH - (vars->map.g_w * vars->map.ppg);
	c = HEIGHT - (vars->map.g_h * vars->map.ppg);
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
	draw_line(vars, mapped_player_pos, mapped_touchpoint, 0xFF0000);
}

void	draw_player(t_vars *vars)
{
	t_point	mapped_player;

	mapped_player = screen_mapping(vars, vars->player.x, vars->player.y);
	draw_square(vars, mapped_player, vars->map.ppg / 4, 0x00FF00);
}

void	draw_map(t_vars *vars)
{
	t_size	y;
	t_size	x;
	t_point	pos;

	vars->map.ppg = HEIGHT / (4 * vars->map.g_h);
	y = 0;
	while (y < vars->map.g_h)
	{
		x = 0;
		while (x < vars->map.g_w)
		{
			if (vars->map.grid[y][x] == '1')
			{
				pos.px_x = WIDTH - 1 - (vars->map.g_w - x) * vars->map.ppg;
				pos.px_y = HEIGHT - 1 - (vars->map.g_h - y) * vars->map.ppg;
				draw_square(vars, pos, vars->map.ppg, 0x0000FF);
			}
			x++;
		}
		y++;
	}
	draw_player(vars);
}
