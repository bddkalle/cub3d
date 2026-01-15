/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:35 by vboxuser          #+#    #+#             */
/*   Updated: 2026/01/13 16:28:20 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_map(t_vars *vars)
{
	int	y;
	int	x;
	int	offset_x;
	int	offset_y;

	offset_x = WIDTH / 4 * 3;
	offset_y = HEIGHT / 4 * 3;
	y = 0;
	while (vars->map.grid[y])
	{
		x = 0;
		while (vars->map.grid[y][x])
		{
			if (vars->map.grid[y][x] == '1')
				draw_square(vars, x * BLOCK / 4 + offset_x, y * BLOCK / 4 + offset_y, BLOCK / 4, 0x0000FF);
			x++;
		}
		y++;
	}
	draw_square(vars, vars->player.x / 4 + offset_x, vars->player.y / 4 + offset_y, 2, 0x00FF00);
}
