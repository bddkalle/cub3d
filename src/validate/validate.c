/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:15:55 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/15 15:12:04 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	validate_no(t_vars *vars, char *line, int fd)
{
	if (vars->map.no.img != NULL)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Found 2nd north texture identifier", \
		"Error\nNO: load_no_textures");
	}
}

void	validate_so(t_vars *vars, char *line, int fd)
{
	if (vars->map.so.img != NULL)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Found 2nd south texture identifier", \
		"Error\nSO: load_so_textures");
	}
}

void	validate_we(t_vars *vars, char *line, int fd)
{
	if (vars->map.we.img != NULL)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Found 2nd west texture identifier", \
		"Error\nWE: load_we_textures");
	}
}

void	validate_ea(t_vars *vars, char *line, int fd)
{
	if (vars->map.ea.img != NULL)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Found 2nd east texture identifier", \
		"Error\nEA: load_ea_textures");
	}
}

void	validate_fileformat(char *s)
{
	int	l;

	l = ft_strlen(s) - 1;
	if (s[l] != 'b' && s[l - 1] != 'u' && s[l - 2] != 'c' && s[l - 3] != '.')
		input_error("Invalid fileformat - .cub file expected");
}

/* int	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	return (1);
}

int	valid_map_chars(t_tile_type tile)
{
	if (tile == FLOOR || tile == WALL || tile == COLLECT || tile == EXIT || \
		tile == START)
		return (1);
	return (0);
}

void	count_chars(t_vars *vars, t_point grid_pos)
{
	if (vars->map.grid[grid_pos.px_y][grid_pos.px_x] == EXIT)
		vars->exit_found++;
	else if (vars->map.grid[grid_pos.px_y][grid_pos.px_x] == COLLECT)
		vars->collect_found++;
	else if (vars->map.grid[grid_pos.px_y][grid_pos.px_x] == START)
	{
		vars->start_found++;
		vars->player.pos = grid_pos;
	}
}

void	validate_map(t_vars *vars, t_point grid_pos)
{
	if (wall_check(vars))
		exit (map_error_fillgrids("No surrounding walls", \
			NULL, vars, grid_pos));
	if (vars->start_found != 1)
		exit (map_error_fillgrids("Invalid start count", \
			NULL, vars, grid_pos));
	valid_path(vars, vars->player.pos);
	if (vars->exit_found != 1)
		exit (map_error_fillgrids("Invalid exit count", \
			NULL, vars, grid_pos));
	else if (vars->map.exit_accessible == 0)
		exit (map_error_fillgrids("Exit not accessible", \
			NULL, vars, grid_pos));
	if (vars->collect_found == 0)
		exit (map_error_fillgrids("No collectible found", \
			NULL, vars, grid_pos));
	else if (vars->map.collect_accessible != vars->collect_found)
		exit (map_error_fillgrids("Not all collectibles accessible", \
			NULL, vars, grid_pos));
}
 */