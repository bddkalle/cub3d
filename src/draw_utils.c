/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahne <cdahne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:08:14 by fschnorr          #+#    #+#             */
/*   Updated: 2026/02/18 10:09:25 by cdahne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	create_argb(int rgb[3])
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

void	draw_square(t_vars *vars, t_point pos, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
		put_pixel(vars, pos.px_x + i, pos.px_y, color);
	i = -1;
	while (++i < size)
		put_pixel(vars, pos.px_x, pos.px_y + i, color);
	i = -1;
	while (++i < size)
		put_pixel(vars, pos.px_x + size, pos.px_y + i, color);
	i = -1;
	while (++i < size)
		put_pixel(vars, pos.px_x + i, pos.px_y + size, color);
}

void	draw_column(t_vars *vars, int ray_id, t_intrsec *w_slc, bool draw_map)
{
	int		y;
	int		color;

	y = HEIGHT - 1;
	while (y >= 0)
	{
		if (draw_map \
			&& (t_size)ray_id >= WIDTH - 1 - (vars->map.g_w * vars->map.ppg) \
			&& (t_size)y >= HEIGHT - 1 - (vars->map.g_h * vars->map.ppg))
			y--;
		else if (y >= w_slc->wall_bottom)
			put_pixel(vars, ray_id, y--, create_argb(vars->map.floor));
		else if (y > w_slc->wall_top)
		{
			color = get_color_from_txt(vars, w_slc, y);
			put_pixel(vars, ray_id, y--, color);
		}
		else
			put_pixel(vars, ray_id, y--, create_argb(vars->map.ceiling));
	}
}

void	draw_line(t_vars *vars, t_point p1, t_point p2, int color)
{
	t_fpoint	p;
	float		dx;
	float		dy;
	float		step;
	int			i;

	dx = (float)p2.px_x - p1.px_x;
	dy = (float)p2.px_y - p1.px_y;
	if (absolute(dx) >= absolute(dy))
		step = absolute(dx);
	else
		step = absolute(dy);
	dx = dx / step;
	dy = dy / step;
	p.x = p1.px_x;
	p.y = p1.px_y;
	i = 0;
	while (i < (int)step)
	{
		put_pixel(vars, (int)p.x, (int)p.y, color);
		p.x += dx;
		p.y += dy;
		i++;
	}
}
