/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:28:22 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 10:38:19 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	fill_grid(t_vars *vars, int fd2, char *line, t_point grid_pos)
{
	while (line)
	{
		alloc_line(vars, grid_pos, line, fd2);
		while (grid_pos.px_x < vars->map.g_w)
		{
			fill_grid_row(vars, grid_pos, line, fd2);
			grid_pos.px_x++;
		}
		grid_pos.px_x = 0;
		free(line);
		line = NULL;
		line = get_next_line(fd2);
		if (line)
			grid_pos.px_y++;
	}
	free(line);
	line = NULL;
	close (fd2);
}

int	prepare_file(t_vars *vars, char *map_begin, char **line2, char *file)
{
	int		fd2;

	fd2 = open(file, O_RDONLY);
	if (fd2 < 0)
	{
		free_null((void **)&map_begin);
		free_null((void **)&vars->map.grid);
		free_null((void **)&vars->map.tile);
		fatal_error(vars, "Could not open .cub file", "open");
	}
	*line2 = get_next_line(fd2);
	if (!*line2)
	{
		close(fd2);
		free_null((void **)&map_begin);
		free_null((void **)&vars->map.grid);
		free_null((void **)&vars->map.tile);
		fatal_error(vars, "Could not read from .cub file", "get_next_line");
	}
	while (ft_strcmp(*line2, map_begin))
	{
		free_null((void **)line2);
		*line2 = get_next_line(fd2);
	}
	return (fd2);
}


int	is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || \
		c == 'E' || c == 'W' || c == ' ')
		return (1);
	return (0);
}

int	map_detected(t_vars *vars, char *s)
{																		// check: alle idents vorhanden?
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

int	init_grid(t_vars *vars, char *map_begin, char **line2, char *file)
{
	int		fd2;

	vars->map.grid = malloc(vars->map.g_h * sizeof(char *));
	if (!vars->map.grid)
	{
		free_null((void **)&map_begin);
		fatal_error(vars, "Could not allocate memory", "init_grid");
	}
	vars->map.tile = malloc(vars->map.g_h * sizeof(t_tile *));
	if (!vars->map.tile)
	{
		free_null((void **)&map_begin);
		free_null((void **)&vars->map.grid);
		fatal_error(vars, "Could not allocate memory", "init_grid");
	}
	fd2 = prepare_file(vars, map_begin, line2, file);
	free_null((void **)&map_begin);
	return (fd2);
}
