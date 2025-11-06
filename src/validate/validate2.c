/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:15:55 by fschnorr          #+#    #+#             */
/*   Updated: 2024/12/05 14:44:10 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	wall_check(t_vars *vars)
{
	t_point	current;

	current.px_x = 0;
	current.px_y = 0;
	while (current.px_x < vars->map.g_w)
	{
		if (vars->map.grid[current.px_y][current.px_x] != WALL)
			return (1);
		current.px_x++;
	}
	while (++current.px_y < (vars->map.g_h - 1))
	{
		if (vars->map.grid[current.px_y][0] != WALL || \
		vars->map.grid[current.px_y][vars->map.g_w - 1] != WALL)
			return (1);
	}
	current.px_x = 0;
	while (current.px_x < vars->map.g_w)
	{
		if (vars->map.grid[current.px_y][current.px_x] != WALL)
			return (1);
		current.px_x++;
	}
	return (0);
}

void	valid_path(t_vars *vars, t_point p)
{
	if (vars->map.tile[p.px_y][p.px_x].type == EXIT)
		vars->map.exit_accessible = 1;
	if (vars->map.tile[p.px_y][p.px_x].type == WALL || \
		vars->map.tile[p.px_y][p.px_x].visited == 1 || \
		p.px_x >= vars->map.g_w || \
		p.px_y >= vars->map.g_h)
		return ;
	vars->map.tile[p.px_y][p.px_x].visited = 1;
	if (vars->map.tile[p.px_y][p.px_x].type == COLLECT)
		vars->map.collect_accessible++;
	valid_path(vars, (t_point){p.px_x - 1, p.px_y});
	valid_path(vars, (t_point){p.px_x + 1, p.px_y});
	valid_path(vars, (t_point){p.px_x, p.px_y - 1});
	valid_path(vars, (t_point){p.px_x, p.px_y + 1});
}
