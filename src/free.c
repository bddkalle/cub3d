/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:36:20 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 10:40:58 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_imgs(t_vars *vars)
{
	if (vars->map.no.img)
	{
		mlx_destroy_image(vars->mlx, vars->map.no.img);
		vars->map.no.img = NULL;
	}

	if (vars->map.so.img)
	{
		mlx_destroy_image(vars->mlx, vars->map.so.img);
		vars->map.so.img = NULL;
	}

	if (vars->map.we.img)
	{
		mlx_destroy_image(vars->mlx, vars->map.we.img);
		vars->map.we.img = NULL;
	}

	if (vars->map.ea.img)
	{
		mlx_destroy_image(vars->mlx, vars->map.ea.img);
		vars->map.ea.img = NULL;
	}
}

void	free_mlx(t_vars *vars)
{
	if (vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->img = NULL;
	}
	if (vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free_null(&vars->mlx);
	}
}

void	free_grid(t_vars *vars)
{
	int	tmp;

	if (vars->map.grid)
	{
		// tmp = grid_pos.px_y + 1;
		tmp = vars->map.g_h;
		while (--tmp >= 0)
		{
			free(vars->map.grid[tmp]);
			vars->map.grid[tmp] = NULL;

		}
		free_null((void **)&vars->map.grid);
	}
	if (vars->map.tile)
	{
		// tmp = grid_pos.px_y + 1;
		tmp = vars->map.g_h;
		while (--tmp >= 0)
		{
			free(vars->map.tile[tmp]);
			vars->map.tile[tmp] = NULL;
		}
		free_null((void **)&vars->map.tile);
	}
	free_null((void **)&vars->map.grid3);		// Loeschen wenn hardcoded map entfernt
}

void	free_all(t_vars *vars)
{
	free_grid(vars);
	free_imgs(vars);
	free_mlx(vars);
}
