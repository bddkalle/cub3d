/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:24:03 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 10:58:34 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	get_map_size(t_map	*map, t_vars *vars, char *line, int fd)
{
	(void)vars;
	while (line && ++map->g_h)
	{
		if (map->g_w < ft_linelen(line))
			map->g_w = ft_linelen(line);
		free_null((void **)&line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	extract_map(t_vars *vars, char *line, int fd, char *file)
{
	t_point	grid_pos;
	char	*map_begin;
	char	*line2;
	int		fd2;

	map_begin = ft_strdup(line);
	if (!map_begin)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "malloc error", "extract_map");
	}
	get_map_size(&vars->map, vars, line, fd);
	fd2 = init_grid(vars, map_begin, &line2, file);
	grid_pos = (t_point){};
	fill_grid(vars, fd2, line2, grid_pos);
}

void	parse_map(t_vars *vars, char *line, int fd, char *file)
{
	extract_map(vars, line, fd, file);
	print_grid(vars);
	validate_map(vars);
	printf("height: %ld\n", vars->map.g_h);
	printf("width: %ld\n", vars->map.g_w);
	vars->map.grid3 = malloc(sizeof(char *) * 11);
	if (!vars->map.grid3)
		fatal_error(vars, "Could not allocate grid", "malloc");
	vars->map.grid3[0] = "111111111111111";
	vars->map.grid3[1] = "100000000000001";
	vars->map.grid3[2] = "100000000000001";
	vars->map.grid3[3] = "100000000000001";
	vars->map.grid3[4] = "100001000000001";
	vars->map.grid3[5] = "100000000000001";
	vars->map.grid3[6] = "100000000000001";
	vars->map.grid3[7] = "100000000011001";
	vars->map.grid3[8] = "100000000000001";
	vars->map.grid3[9] = "111111111111111";
	vars->map.grid3[10] = NULL;
}
