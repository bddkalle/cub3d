/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:42:14 by fschnorr          #+#    #+#             */
/*   Updated: 2026/02/17 17:08:26 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	run_game(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_win, vars);
	mlx_loop_hook(vars->mlx, draw_img, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		validate_fileformat(argv[1]);
		init_game(&vars, argv[1]);
		run_game(&vars);
	}
	else if (argc == 1)
		input_error("Specify map file");
	else
		input_error("Too many arguments. USAGE: ./cub3D [filename].cub");
	return (0);
}
