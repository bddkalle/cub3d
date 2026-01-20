/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:01:35 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/20 20:12:26 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_player(t_vars *vars, t_point p)
{
	if (vars->map.grid[p.px_y][p.px_x] == 'N')
		vars->player.alpha = -PI / 2.0;
	else if (vars->map.grid[p.px_y][p.px_x] == 'E')
		vars->player.alpha = 0;
	else if (vars->map.grid[p.px_y][p.px_x] == 'S')
		vars->player.alpha = PI / 2.0;
	else if (vars->map.grid[p.px_y][p.px_x] == 'W')
		vars->player.alpha = PI;
	vars->player.start = p;
	vars->player.x = (float)p.px_x * BLOCK + BLOCK / 2.0;
	vars->player.y = (float)p.px_y * BLOCK + BLOCK / 2.0;
}

void	init_player(t_player *player)
{
	*player = (t_player){};
}

void	rotate_player(t_vars *vars, float angle_speed)
{
	if (vars->player.left_rotate)
		vars->player.alpha -= angle_speed;
	if (vars->player.right_rotate)
		vars->player.alpha += angle_speed;
	if (vars->player.alpha > 2 * PI)
		vars->player.alpha -= 2 * PI;
	if (vars->player.alpha < 0)
		vars->player.alpha += 2 * PI;
}

bool	wall_collision(t_vars *vars, float x_inc, float y_inc)
{
	float	x;
	float	y;

	x = vars->player.x + x_inc;
	y = vars->player.y + y_inc;
	if (touch(vars, x, y))
		return (true);
	return (false);
}

void	transpose_player(t_vars *vars, float cos_inc, float sin_inc)
{
	if (vars->player.key_up && !wall_collision(vars, cos_inc, sin_inc))
	{
		vars->player.x += cos_inc;
		vars->player.y += sin_inc;
	}
	if (vars->player.key_down && !wall_collision(vars, -cos_inc, -sin_inc))
	{
		vars->player.x -= cos_inc;
		vars->player.y -= sin_inc;
	}
	if (vars->player.key_left && !wall_collision(vars, sin_inc, -cos_inc))
	{
		vars->player.x += sin_inc;
		vars->player.y -= cos_inc;
	}
	if (vars->player.key_right && !wall_collision(vars, -sin_inc, cos_inc))
	{
		vars->player.x -= sin_inc;
		vars->player.y += cos_inc;
	}
}

void	move_player(t_vars *vars)
{
	int		speed;
	float	angle_speed;
	float	cos_inc;
	float	sin_inc;

	speed = 3;
	angle_speed = 0.05;
	if (!isfinite(vars->player.alpha))
		fatal_error(vars, "Player alpha is infinite.", "cos/sin");
	cos_inc = speed * cos(vars->player.alpha);
	sin_inc = speed * sin(vars->player.alpha);
	rotate_player(vars, angle_speed);
	transpose_player(vars, cos_inc, sin_inc);
}
