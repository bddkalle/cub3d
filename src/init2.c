
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:55:06 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/21 16:53:28 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_floor_color(t_vars *vars, char *line, int i, int fd)
{
	char	**color_arr;

	validate_f(vars, line, fd);
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	if (!valid_c(&line[i]) || ft_count_c(',', &line[i]) != 2)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Invalid color number format", "set_floor_color");
	}
	color_arr = ft_split(&line[i], ',');
	parse_floor_color(vars, line, fd, color_arr);
	free_null((void **)&color_arr[0]);
	free_null((void **)&color_arr[1]);
	free_null((void **)&color_arr[2]);
	free_null((void **)&color_arr);
	vars->map.floor[3] += 1;
}

void	load_so_textures(t_vars *vars, char *line, int i, int fd)
{
	char	*filename;

	validate_so(vars, line, fd);
	filename = ft_strtrim(&line[i], " \n");
	if (!filename)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Could not trim path to texture", \
		"Error\nSO: ft_strtrim");
	}
	vars->map.so.img = mlx_xpm_file_to_image(vars->mlx, filename, \
	&vars->map.so.px_w, &vars->map.so.px_h);
	if (!vars->map.so.img)
	{
		close(fd);
		free_null((void **)&line);
		free_null((void **)&filename);
		get_next_line(-1);
		fatal_error(vars, "Could not create south texture", \
	"Error\nSO: mlx_xpm_file_to_image");
	}
	free_null((void **)&filename);
	set_img_addr(vars, line, fd, vars->map.so);
}

void	load_we_textures(t_vars *vars, char *line, int i, int fd)
{
	char	*filename;

	validate_we(vars, line, fd);
	filename = ft_strtrim(&line[i], " \n");
	if (!filename)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Could not trim path to texture", \
		"Error\nWE: ft_strtrim");
	}
	vars->map.we.img = mlx_xpm_file_to_image(vars->mlx, filename, \
	&vars->map.we.px_w, &vars->map.we.px_h);
	if (!vars->map.we.img)
	{
		close(fd);
		free_null((void **)&line);
		free_null((void **)&filename);
		get_next_line(-1);
		fatal_error(vars, "Could not create west texture", \
	"Error\nWE: mlx_xpm_file_to_image");
	}
	free_null((void **)&filename);
	set_img_addr(vars, line, fd, vars->map.we);
}

void	load_ea_textures(t_vars *vars, char *line, int i, int fd)
{
	char	*filename;

	validate_ea(vars, line, fd);
	filename = ft_strtrim(&line[i], " \n");
	if (!filename)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Could not trim path to texture", \
		"Error\nEA: ft_strtrim");
	}
	vars->map.ea.img = mlx_xpm_file_to_image(vars->mlx, filename, \
	&vars->map.ea.px_w, &vars->map.ea.px_h);
	if (!vars->map.ea.img)
	{
		close(fd);
		free_null((void **)&line);
		free_null((void **)&filename);
		get_next_line(-1);
		fatal_error(vars, "Could not create east texture", \
	"Error\nEA: mlx_xpm_file_to_image");
	}
	free_null((void **)&filename);
	set_img_addr(vars, line, fd, vars->map.ea);
}

void	load_no_textures(t_vars *vars, char *line, int i, int fd)
{
	char	*filename;

	validate_no(vars, line, fd);
	filename = ft_strtrim(&line[i], " \n");
	if (!filename)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Could not trim path to texture", \
		"Error\nNO: ft_strtrim");
	}
	vars->map.no.img = mlx_xpm_file_to_image(vars->mlx, filename, \
	&vars->map.no.px_w, &vars->map.no.px_h);
	if (!vars->map.no.img)
	{
		close(fd);
		free_null((void **)&line);
		free_null((void **)&filename);
		get_next_line(-1);
		fatal_error(vars, "Could not create north texture", \
	"Error\nNO: mlx_xpm_file_to_image");
	}
	free_null((void **)&filename);
	set_img_addr(vars, line, fd, vars->map.no);
}
