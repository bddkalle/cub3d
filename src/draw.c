/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:36:29 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/11 14:33:15 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	touch(float px, float py, t_vars *vars)
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

void	draw_ray(t_vars *vars, float start_angle)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;

	ray_x = vars->player.x;
	ray_y = vars->player.y;
	cos_angle = cos(start_angle);
	sin_angle = -sin(start_angle);
	while (!touch(ray_x, ray_y, vars))
	{
		put_pixel(vars, ray_x, ray_y, 0xFF0000);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

void	draw_fov(t_vars *vars)
{
	float	fraction;
	float	start_angle;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_angle = vars->player.angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_ray(vars, start_angle);
		start_angle += fraction;
		i++;
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

