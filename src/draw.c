/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:36:29 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/12 15:10:01 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"
#include <stdbool.h>

bool	touch(t_vars *vars, float px, float py)
{
	int	x;
	int y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (vars->map.grid[y][x] == '1')
		return (true);
	else
		return (false);
}

float	distance(float dx, float dy)
{
	return (sqrt(dx * dx + dy * dy));
}

void	draw_line(t_vars *vars, float ray_x, float ray_y, int ray)
{
	float	d;
	float	h;
	int		start_y;
	int		end;

	d = distance(ray_x - vars->player.x, ray_y - vars->player.y);
	h = (BLOCK / d) * (WIDTH / 2.0);


	start_y = (HEIGHT - h) / 2;
	end = start_y + h;
	while (start_y < end)
	{
		put_pixel(vars, ray, start_y, 0x0000FF);
		start_y++;
	}
}

void	cast_ray(t_vars *vars, float alpha, int ray, bool draw_map)
{
	float	ray_x;
	float	ray_y;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	while (!touch(vars, ray_x, ray_y))
	{
		if (draw_map)
			put_pixel(vars, ray_x, ray_y, 0xFF0000);
		ray_x += cos(alpha);
		ray_y -= sin(alpha);
	}
	draw_line(vars, ray_x, ray_y, ray);
}

void	draw_fov(t_vars *vars)
{
	float	fraction;
	float	fov_min;
	int		ray;

	fraction = PI / 3 / WIDTH;
	fov_min = vars->player.alpha - PI / 6;
	ray = 0;
	while (ray < WIDTH)
	{
		cast_ray(vars, fov_min, ray, true);
		fov_min += fraction;
		ray++;
	}
}

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map.grid[y])
	{
		x = 0;
		while (vars->map.grid[y][x])
		{
			if (vars->map.grid[y][x] == '1')
				draw_square(vars, x * BLOCK, y * BLOCK, BLOCK, 0x0000FF);
			x++;
		}
		y++;
	}
}

void	clear_image(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(vars, x, y, 0);
			x++;
		}
		y++;
	}
}

int	draw_img(t_vars *vars)
{
	move_player(vars);
	clear_image(vars);
	draw_map(vars);
	draw_square(vars, vars->player.x, vars->player.y, 10, 0x00FF00);
	draw_fov(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	int	index;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	index = y * vars->size_line + x * vars->bpp / 8;
	vars->img_addr[index] = color & 0xFF;
	vars->img_addr[index + 1] = (color >> 8) & 0xFF;
	vars->img_addr[index + 2] = (color >> 16) & 0xFF;
}


void	draw_square(t_vars *vars, int x, int y, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
		put_pixel(vars, x + i, y, color);
	i = -1;
	while (++i < size)
		put_pixel(vars, x, y + i, color);
	i = -1;
	while (++i < size)
		put_pixel(vars, x + size, y + i, color);
	i = -1;
	while (++i < size)
		put_pixel(vars, x + i, y + size, color);
}

