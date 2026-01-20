/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:35 by vboxuser          #+#    #+#             */
/*   Updated: 2026/01/20 11:50:26 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_point	screen_mapping(t_vars *vars, float x, float y)
{
	float	a;
	float	b;
	float	c;
	float	d;
	t_point	mapped_p;

	a = vars->map.pixel_per_grid * (1.0 - 1.0 / vars->map.g_w);
	b = WIDTH - (vars->map.g_w * vars->map.pixel_per_grid);
	mapped_p.px_x = a * x + b;
	c = vars->map.pixel_per_grid * (1.0 - 1.0 / vars->map.g_h);
	d = HEIGHT - (vars->map.g_h * vars->map.pixel_per_grid);
	mapped_p.px_y = c * y + d;
	return (mapped_p);
}

void	draw_ray(t_vars *vars, float ray_x, float ray_y)
{
	//put_pixel(vars,(int)ray_x / 4 + WIDTH / 4 * 3, (int)ray_y / 4 + HEIGHT / 4 * 3, 0xFF0000);
	t_point	mapped_p;

	mapped_p = screen_mapping(vars, ray_x, ray_y);
	put_pixel(vars,\
		mapped_p.px_x, mapped_p.px_y, 0xFF0000);

}

void	draw_player(t_vars *vars)
{
	t_point	mapped_player;

	mapped_player = screen_mapping(vars, vars->player.x, vars->player.y);
	printf("player x: %f, y: %f, mapped_x: %lu, mapped_y: %lu\n", vars->player.x, vars->player.y, mapped_player.px_x, mapped_player.px_y);
	draw_square(vars,\
		mapped_player.px_x,\
		mapped_player.px_y,\
		8,
		0x00FF00);
}
/*
void	draw_player(t_vars *vars)
{
	t_point	p;
	int		px_res;
	int		py_res;

	p.px_x = vars->player.x / BLOCK;
	p.px_y = vars->player.y / BLOCK;
	px_res = (int)vars->player.x % BLOCK * (vars->map.pixel_per_grid / BLOCK);
	py_res = (int)vars->player.x % BLOCK * (vars->map.pixel_per_grid / BLOCK);

	draw_square(vars,\
		WIDTH - (vars->map.g_w - p.px_x) * vars->map.pixel_per_grid + px_res,\
		HEIGHT - (vars->map.g_h - p.px_y) * vars->map.pixel_per_grid + py_res,\
		vars->map.pixel_per_grid / 16,\
		0x00FF00);
}*/

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
