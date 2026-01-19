/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:15:55 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 00:23:20 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	validate_map(t_vars *vars)
{
	if (vars->map.start_found != 1)
		fatal_error(vars, "Invalid start count", "validate_map");
	if (wall_check(vars))
		fatal_error(vars, "No surrounding walls", "validate_map");
}


int	valid_map_chars(t_tile_type tile)
{
	// printf("tile = %d\n", tile);
	if (tile == FLOOR || tile == WALL || tile == NORTH_SP || tile == SOUTH_SP \
	|| tile == EAST_SP || tile == WEST_SP || tile == SPACE)
		return (1);
	return (0);
}

void	validate_c(t_vars *vars, char *line, int fd)
{
	if (vars->map.ceiling[3] > 0)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Found 2nd ceiling identifier", \
		"CEILING: cub_interpreter");
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
		"FLOOR: cub_interpreter");
	}
}


void	validate_textures(t_vars *vars)
{
	if (!vars->map.no.img)
		fatal_error(vars, "Missing north texture", \
		"cub_interpreter");
	else if (!vars->map.so.img)
		fatal_error(vars, "Missing south texture", \
		"cub_interpreter");
	else if (!vars->map.we.img)
		fatal_error(vars, "Missing west texture", \
		"cub_interpreter");
	else if (!vars->map.ea.img)
		fatal_error(vars, "Missing east texture", \
		"cub_interpreter");
	else if (!vars->map.floor[3])
		fatal_error(vars, "Missing floor color", \
		"cub_interpreter");
	else if (!vars->map.ceiling[3])
		fatal_error(vars, "Missing ceiling color", \
		"cub_interpreter");
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