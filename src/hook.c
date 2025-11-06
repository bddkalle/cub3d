/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:46:34 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/06 14:37:10 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	if (keycode == W)
		vars->player.key_up = true;
	if (keycode == A)
		vars->player.key_left = true;
	if (keycode == S)
		vars->player.key_down = true;
	if (keycode == D)
		vars->player.key_right = true;
	if (keycode == LEFT)
		vars->player.left_rotate = true;
	if (keycode == RIGHT)
		vars->player.right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == W)
		vars->player.key_up = false;
	if (keycode == A)
		vars->player.key_left = false;
	if (keycode == S)
		vars->player.key_down = false;
	if (keycode == D)
		vars->player.key_right = false;
	if (keycode == LEFT)
		vars->player.left_rotate = false;
	if (keycode == RIGHT)
		vars->player.right_rotate = false;

	return (0);
}

int	close_win(t_vars *vars)
{
	//free_sprites(vars);
	free_all(vars);
	//free_grid(vars);
	exit (0);
}
