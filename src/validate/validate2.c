/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:15:55 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/15 16:04:54 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	validate_c(t_vars *vars, char *line, int fd)
{
	if (vars->map.ceiling[3] > 0)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Found 2nd ceiling identifier", \
		"Error\nCEILING: cub_interpreter");
	}
}

void	validate_f(t_vars *vars, char *line, int fd)
{
	if (vars->map.floor[3] > 0)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Found 2nd floor identifier", \
		"Error\nFLOOR: cub_interpreter");
	}
}


void	validate_textures(t_vars *vars)
{
	if (!vars->map.no.img)
		fatal_error(vars, "Missing north texture", \
		"Error\ncub_interpreter");
	if (!vars->map.so.img)
		fatal_error(vars, "Missing south texture", \
		"Error\ncub_interpreter");

	if (!vars->map.we.img)
		fatal_error(vars, "Missing west texture", \
		"Error\ncub_interpreter");

	if (!vars->map.ea.img)
		fatal_error(vars, "Missing east texture", \
		"Error\ncub_interpreter");

}


/* int	wall_check(t_vars *vars)
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
 */