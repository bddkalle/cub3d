/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:36:29 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/15 16:35:55 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_fov(t_vars *vars)
{
	float	rad_per_pixel;
	float	fov_min;
	int		ray_id;

	rad_per_pixel = PI / 3 / WIDTH;
	fov_min = vars->player.alpha - PI / 6;
	ray_id = 0;
	while (ray_id < WIDTH)
	{
		cast_ray(vars, fov_min, ray_id, true);
		fov_min += rad_per_pixel;
		ray_id++;
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
	printf("NO texture: %p\n", vars->map.no.img);
	printf("floor %d,%d,%d\n", vars->map.floor[0], vars->map.floor[1], vars->map.floor[2]);
	draw_fov(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	//wall_detector_helper(vars);
	return (0);
}

