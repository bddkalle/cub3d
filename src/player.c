/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:01:35 by fschnorr          #+#    #+#             */
/*   Updated: 2025/12/28 19:55:38 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_player(t_player *player)
{
	*player = (t_player){};
	player->x = WIDTH / 2.0;
	player->y = HEIGHT / 2.0;
	player->alpha = PI / 2.0;
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
