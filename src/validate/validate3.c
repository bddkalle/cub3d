/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:15:55 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 23:30:11 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_open_wall(t_vars *vars, int y, int x)
{
	if (y < 0 || x < 0 || y > (int)vars->map.g_h || x > (int)vars->map.g_w)
		return (1);
	else if (vars->map.tile[y][x].visited)
		return (0);
	else if (vars->map.grid[y][x] == ' ')
		return (1);
	else if (vars->map.grid[y][x] == '1')
		return (0);
	vars->map.tile[y][x].visited = 1;
	if (check_open_wall(vars, y - 1, x))
		return (1);
	if (check_open_wall(vars, y + 1, x))
		return (1);
	if (check_open_wall(vars, y, x - 1))
		return (1);
	if (check_open_wall(vars, y, x + 1))
		return (1);
	return (0);
}

t_point	find_start_set_player(t_vars *vars)
{
	t_point	p;

	p = (t_point){};
	while (p.px_y < vars->map.g_h)
	{
		p.px_x = 0;
		while (p.px_x < vars->map.g_w)
		{
			if (vars->map.grid[p.px_y][p.px_x] == 'N' ||
			vars->map.grid[p.px_y][p.px_x] == 'S' ||
			vars->map.grid[p.px_y][p.px_x] == 'E' ||
			vars->map.grid[p.px_y][p.px_x] == 'W')
			{
				set_player(vars, p);
				return (p);
			}
			p.px_x++;
		}
		p.px_y++;
	}
	fatal_error(vars, "Could not find start point", "validate_map");
	return ((t_point){});
}

int	wall_check(t_vars *vars)
{
	t_point	start;

	start = find_start_set_player(vars);
	// printf("Startpoint: x = %ld, y = %ld\n", start.px_x, start.px_y);
	if (check_open_wall(vars, start.px_y, start.px_x))
		fatal_error(vars, "Map is not closed", "wall_check");
	return (0);
}
