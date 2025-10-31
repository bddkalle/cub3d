/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:46:34 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/31 16:26:05 by fschnorr         ###   ########.fr       */
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
	return (0);
}

int	close_win(t_vars *vars)
{
	//free_sprites(vars);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = NULL;
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = NULL;
	//free_grid(vars);
	exit (0);
}
