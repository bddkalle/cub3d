/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:08:14 by fschnorr          #+#    #+#             */
/*   Updated: 2026/02/17 17:07:20 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	create_argb(int	rgb[3])
{
	return (0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
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

void	draw_column(t_vars *vars, int ray_id, t_intrsec *wall_slice, bool draw_map)
{
	int		y;
	int		color;

	y = HEIGHT - 1;
	while (y >= 0)
	{
		if (draw_map\
			&& (t_size)ray_id >= WIDTH - 1 - (vars->map.g_w * vars->map.pixel_per_grid)\
			&& (t_size)y >= HEIGHT - 1 - (vars->map.g_h * vars->map.pixel_per_grid))
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

void	draw_line(t_vars *vars, t_point p1, t_point p2, int color)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;
	int		i;

	dx = (float)p2.px_x - p1.px_x;
	dy = (float)p2.px_y - p1.px_y;
	if (absolute(dx) >= absolute(dy))
		step = absolute(dx);
	else
		step = absolute(dy);
	dx = dx / step;
	dy = dy / step;
	x = p1.px_x;
	y = p1.px_y;
	i = 0;
	while (i < (int)step)
	{
		put_pixel(vars, (int)x, (int)y, color);
		x += dx;
		y += dy;
		i++;
	}
}
