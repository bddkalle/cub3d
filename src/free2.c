/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:36:20 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 10:41:17 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_incomplete_grid(t_vars *vars, t_point grid_pos)
{
	int	tmp;

	tmp = grid_pos.px_y + 1;
	while (--tmp >= 0)
	{
		free(vars->map.grid[tmp]);
		vars->map.grid[tmp] = NULL;
		free(vars->map.tile[tmp]);
		vars->map.tile[tmp] = NULL;
	}
	free(vars->map.grid);
	vars->map.grid = NULL;
	free(vars->map.tile);
	vars->map.tile = NULL;
}
