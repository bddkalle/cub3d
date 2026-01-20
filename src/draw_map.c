/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:35 by vboxuser          #+#    #+#             */
/*   Updated: 2026/01/20 10:36:06 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_map(t_vars *vars)
{
	t_size	y;
	t_size	x;
	int	pixel_per_grid;

	pixel_per_grid = HEIGHT / (4 * vars->map.g_h);
	y = 0;
	while (y < vars->map.g_h)
	{
		x = 0;
		while (x < vars->map.g_w)
		{
			if (vars->map.grid[y][x] == '1')
				draw_square(vars,\
					WIDTH - (vars->map.g_w - x) * pixel_per_grid,\
					HEIGHT - (vars->map.g_h - y) * pixel_per_grid,\
					pixel_per_grid, 0x0000FF);
			x++;
		}
		y++;
	}
	//draw_square(vars, WIDTH - (vars->map.g_w - x) * pixel_per_grid, vars->player.y / 4 + offset_y, 2, 0x00FF00);
}

/*
void	draw_map(t_vars *vars)
{
	t_size	y;
	t_size	x;
	int	offset_x;
	int	offset_y;

	int	pixel_per_grid;

	pixel_per_grid = (WIDTH / 4) * 3 / vars->map.g_h;

	offset_x = WIDTH / 4 * 3;
	offset_y = HEIGHT / 4 * 3;
	y = 0;
	while (y < vars->map.g_h)
	{
		x = 0;
		while (x < vars->map.g_w)
		{
			if (vars->map.grid[y][x] == '1')
				draw_square(vars, x * BLOCK / 4 + offset_x, y * BLOCK / 4 + offset_y, BLOCK / 4, 0x0000FF);
			x++;
		}
		y++;
	}
	draw_square(vars, vars->player.x / 4 + offset_x, vars->player.y / 4 + offset_y, 2, 0x00FF00);
}*/
