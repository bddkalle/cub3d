/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:28:22 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/15 22:19:58 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || \
		c == 'E' || c == 'W' || c == ' ')
		return (1);
	return (0);
}

int	map_detected(t_vars *vars, char *s)
{																		// check: alle idents vorhanden
	if (vars->map.no.img != NULL && vars->map.so.img != NULL \
	&& vars->map.we.img != NULL && vars->map.ea.img != NULL \
	&& vars->map.floor[3] == 1 && vars->map.ceiling[3] == 1)
	{
		if (!is_map_char(*s))
			return (0);
		while (is_map_char(*s))
			s++;
		if (*s == '\n')
			return (1);
	}
	return (0);
}

/* void	init_grid_fill(t_vars *vars, t_point *grid_pos)
{
	vars->map.fd = open(vars->map.file_path, O_RDONLY);
	if (vars->map.fd == -1)
		exit (map_error("Could not open map file"));
	vars->map.grid = malloc(vars->map.g_h * sizeof(char *));
	if (!vars->map.grid)
		exit (map_error("Could not allocate memory"));
	vars->map.tile = malloc(vars->map.g_h * sizeof(t_tile *));
	if (!vars->map.tile)
	{
		free(vars->map.grid);
		vars->map.grid = NULL;
		close(vars->map.fd);
		exit (map_error("Could not allocate memory"));
	}
	grid_pos->px_x = 0;
	grid_pos->px_y = 0;
}

void	alloc_line(t_vars *vars, t_point p, char *line)
{
	vars->map.grid[p.px_y] = malloc((vars->map.g_w) * sizeof(char));
	if (!vars->map.grid[p.px_y])
	{
		free(vars->map.grid);
		vars->map.grid = NULL;
		free(vars->map.tile);
		vars->map.tile = NULL;
		exit (map_error_freestash("Could not allocate memory", line, \
		vars->map.fd, &vars->gnl));
	}
	vars->map.tile[p.px_y] = malloc((vars->map.g_w) * sizeof(t_tile));
	if (!vars->map.tile[p.px_y])
	{
		free(vars->map.grid[p.px_y]);
		vars->map.grid[p.px_y] = NULL;
		free(vars->map.grid);
		vars->map.grid = NULL;
		free(vars->map.tile);
		vars->map.tile = NULL;
		exit (map_error_freestash("Could not allocate memory", line, \
		vars->map.fd, &vars->gnl));
	}
}

void	fill_grids(t_vars *vars, t_point grid_pos, char *line)
{
	vars->map.grid[grid_pos.px_y][grid_pos.px_x] = line[grid_pos.px_x];
	vars->map.tile[grid_pos.px_y][grid_pos.px_x].type = line[grid_pos.px_x];
	vars->map.tile[grid_pos.px_y][grid_pos.px_x].visited = 0;
	if (!valid_map_chars(vars->map.tile[grid_pos.px_y][grid_pos.px_x].type))
	{
		exit (map_error_fillgrids("Invalid character used in map file", \
			line, vars, grid_pos));
	}
	count_chars(vars, grid_pos);
}
 */