/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:01:35 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/05 16:10:51 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_player(t_player *player)
{
	*player = (t_player){};
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;
}

void	move_player(t_vars *vars)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 1;
	angle_speed = 0.05;
	if (!isfinite(vars->player.angle))
		fatal_error(vars, "Player angle is infinite.", "cos/sin");
	cos_angle = cos(vars->player.angle);
	sin_angle = sin(vars->player.angle);
	if (vars->player.left_rotate)
		vars->player.angle += angle_speed;
	if (vars->player.right_rotate)
		vars->player.angle -= angle_speed;
	if (vars->player.angle > 2 * PI)
		vars->player.angle -= 2 * PI;
	if (vars->player.angle < 0)
		vars->player.angle += 2 * PI;
	if (vars->player.key_up)
	{
		vars->player.x += cos_angle * speed;
		vars->player.y -= sin_angle * speed;
	}
//		player->y -= speed;
	if (vars->player.key_down)
	{
		vars->player.x -= cos_angle * speed;
		vars->player.y += sin_angle * speed;
	}
		// player->y += speed;
	if (vars->player.key_left)
	{
		vars->player.x -= sin_angle * speed;
		vars->player.y += cos_angle * speed;
	}
		// player->x -= speed;
	if (vars->player.key_right)
	{
		vars->player.x += sin_angle * speed;
		vars->player.y -= cos_angle * speed;
	}
		// player->x += speed;
}
