/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:36:20 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/07 15:05:53 by fschnorr         ###   ########.fr       */
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

void	free_all(t_vars *vars)
{
	free_null((void **)&vars->map.grid);
	free_mlx(vars);
}
