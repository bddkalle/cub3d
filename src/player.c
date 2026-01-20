/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:01:35 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 23:55:11 by fschnorr         ###   ########.fr       */
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
	// vars->player.x = p.px_x * BLOCK + BLOCK / 2;				Versuch 1
	// vars->player.y = p.px_y * BLOCK + BLOCK / 2;
	// vars->player.x = WIDTH / BLOCK * p.px_x + BLOCK / 2;		Versuch 2		beides kompiliert nicht, daher habe ich vorerst die pauschale Initialisierung gelassen
	// vars->player.y = HEIGHT / BLOCK * p.px_y + BLOCK / 2;
	vars->player.x = WIDTH / 2;
	vars->player.y = HEIGHT / 2;
	printf("Startpoint: x = %ld, y = %ld, alpha = %f\n", \
	vars->player.start.px_x, vars->player.start.px_y, vars->player.alpha);
}

void	init_player(t_player *player)
{
	*player = (t_player){};
}

void	move_player(t_vars *vars)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 3;
	angle_speed = 0.05;
	if (!isfinite(vars->player.alpha))
		fatal_error(vars, "Player angle is infinite.", "cos/sin");
	cos_angle = cos(vars->player.alpha);
	sin_angle = sin(vars->player.alpha);
	if (vars->player.left_rotate)
		vars->player.alpha -= angle_speed;
	if (vars->player.right_rotate)
		vars->player.alpha += angle_speed;
	if (vars->player.alpha > 2 * PI)
		vars->player.alpha -= 2 * PI;
	if (vars->player.alpha < 0)
		vars->player.alpha += 2 * PI;
	if (vars->player.key_up)
	{
		vars->player.x += cos_angle * speed;
		vars->player.y += sin_angle * speed;
	}
//		player->y -= speed;
	if (vars->player.key_down)
	{
		vars->player.x -= cos_angle * speed;
		vars->player.y -= sin_angle * speed;
	}
		// player->y += speed;
	if (vars->player.key_left)
	{
		vars->player.x += sin_angle * speed;
		vars->player.y -= cos_angle * speed;
	}
		// player->x -= speed;
	if (vars->player.key_right)
	{
		vars->player.x -= sin_angle * speed;
		vars->player.y += cos_angle * speed;
	}
		// player->x += speed;
}
