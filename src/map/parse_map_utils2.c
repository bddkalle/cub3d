/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:28:22 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 10:40:02 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	count_start(t_vars *vars, t_point grid_pos)
{
	if (vars->map.grid[grid_pos.px_y][grid_pos.px_x] == NORTH_SP ||
	vars->map.grid[grid_pos.px_y][grid_pos.px_x] == SOUTH_SP ||
	vars->map.grid[grid_pos.px_y][grid_pos.px_x] == EAST_SP ||
	vars->map.grid[grid_pos.px_y][grid_pos.px_x] == WEST_SP)
		vars->map.start_found++;
}


void	alloc_line(t_vars *vars, t_point p, char *line, int fd2)
{
	vars->map.grid[p.px_y] = malloc((vars->map.g_w) * sizeof(char));
	if (!vars->map.grid[p.px_y])
	{
		close(fd2);
		get_next_line(-1);
		free_null((void **)&line);
		free_null((void **)&vars->map.grid);
		free_null((void **)&vars->map.tile);
		fatal_error(vars, "Could not allocate memory", "fill_grid");
	}
	vars->map.tile[p.px_y] = malloc((vars->map.g_w) * sizeof(t_tile));
	if (!vars->map.tile[p.px_y])
	{
		close(fd2);
		get_next_line(-1);
		free_null((void **)&line);
		free_null((void **)&vars->map.grid[p.px_y]);					// P: Vorherige Lines werden nicht gefreed! (free_incomplete_grid?)
		free_null((void **)&vars->map.grid);
		free_null((void **)&vars->map.tile);
		fatal_error(vars, "Could not allocate memory", "fill_grid");
	}
}


void	fill_grid_row(t_vars *vars, t_point grid_pos, char *line, int fd2)
{
	if (ft_linelen(line) <= grid_pos.px_x || line[grid_pos.px_x] == '\t')
	{
		vars->map.grid[grid_pos.px_y][grid_pos.px_x] = ' ';
		vars->map.tile[grid_pos.px_y][grid_pos.px_x].type = ' ';
	}
	else
	{
		vars->map.grid[grid_pos.px_y][grid_pos.px_x] = line[grid_pos.px_x];
		vars->map.tile[grid_pos.px_y][grid_pos.px_x].type = line[grid_pos.px_x];
	}
	vars->map.tile[grid_pos.px_y][grid_pos.px_x].visited = 0;
	if (!valid_map_chars(vars->map.tile[grid_pos.px_y][grid_pos.px_x].type))
	{
		close(fd2);
		get_next_line(-1);
		free_null((void **)&line);
		free_incomplete_grid(vars, grid_pos);
		fatal_error(vars, "Invalid character used in map", "fill_grid_line");
	}
	count_start(vars, grid_pos);
}
