/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:55:06 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/06 16:32:47 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_map(t_vars *vars)
{
	//get_map_size()
	parse_map(vars);
}

void	init_vars(t_vars *vars)
{
	*vars = (t_vars){};
	init_player(&vars->player);
}

void	init_game(t_vars *vars)
{
	init_vars(vars);
	cub_interpreter(vars);
	init_map(vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		fatal_error(vars, "Could not initiate mlx session", "mlx_init");
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "cub3D");
	if (!vars->win)
		fatal_error(vars, "Could not initiate new window", "mlx_new_window");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);	//is buffer needed or directly img?
	if (!vars->img)
		fatal_error(vars, "Could not initiate buffer image", "mlx_new_image");
	vars->img_addr = mlx_get_data_addr(vars->img, &vars->bpp, \
		&vars->size_line, &vars->endian);
	if (!vars->img_addr)
		fatal_error(vars, "Could not get memory address of image", \
		"mlx_get_data_addr");
}
