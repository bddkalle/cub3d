/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:24:03 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/05 16:31:24 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

/* void	get_map_size(t_map	*map, t_vars *vars)
{
	int		fd;
	char	*line;

	fd = open(map->file_path, O_RDONLY);
	if (fd < 0)
		exit (map_error("Could not open map file"));
	map->g_h = 0;
	map->g_w = 0;
	line = get_next_line(fd, &vars->gnl);
	while (line && ++map->g_h)
	{
		if (map->g_h == 1)
			map->g_w = ft_linelen(line);
		else if (map->g_w != ft_linelen(line))
			exit (map_error_freestash("map is not rectangular", \
			line, fd, &vars->gnl));
		free(line);
		line = NULL;
		line = get_next_line(fd, &vars->gnl);
	}
	close(fd);
	if (map->g_h == 0)
		exit (map_error("Empty map"));
}
 */
void	parse_map(t_vars *vars)
{
	vars->map.grid = malloc(sizeof(char *) * 11);
	if (!vars->map.grid)
		fatal_error(vars, "Could not allocate grid", "malloc");
	vars->map.grid[0] = "111111111111111";
	vars->map.grid[1] = "100000000000001";
	vars->map.grid[2] = "100000000000001";
	vars->map.grid[3] = "100000000000001";
	vars->map.grid[4] = "100001000000001";
	vars->map.grid[5] = "100000000000001";
	vars->map.grid[6] = "100000000000001";
	vars->map.grid[7] = "100000000011001";
	vars->map.grid[8] = "100000000000001";
	vars->map.grid[9] = "111111111111111";
	vars->map.grid[10] = NULL;
	
	// t_point	grid_pos;
	// char	*line;

	// vars->gnl.stash = NULL;
	// init_grid_fill(vars, &grid_pos);
	// line = get_next_line(vars->map.fd, &vars->gnl);
	// while (line)
	// {
	// 	alloc_line(vars, grid_pos, line);
	// 	while (grid_pos.px_x < vars->map.g_w)
	// 	{
	// 		fill_grids(vars, grid_pos, line);
	// 		grid_pos.px_x++;
	// 	}
	// 	grid_pos.px_x = 0;
	// 	free(line);
	// 	line = NULL;
	// 	line = get_next_line(vars->map.fd, &vars->gnl);
	// 	if (line)
	// 		grid_pos.px_y++;
	// }
	// free(line);
	// line = NULL;
	// close (vars->map.fd);
	// validate_map(vars, grid_pos);
}
