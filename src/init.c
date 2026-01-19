/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:55:06 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/19 12:39:47 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*parse_textures(t_vars *vars, char *line, int fd)
{
	int	i;

	while (line)
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (ft_strncmp("NO", &line[i], 2) == 0)	//handle North texture
			load_no_textures(vars, line, i+2, fd);
		else if (ft_strncmp("SO", &line[i], 2) == 0)	//handle South texture
			load_so_textures(vars, line, i+2, fd);
		else if (ft_strncmp("WE", &line[i], 2) == 0)	//handle West texture
			load_we_textures(vars, line, i+2, fd);
		else if (ft_strncmp("EA", &line[i], 2) == 0)	//handle East texture
			load_ea_textures(vars, line, i+2, fd);
		else if (ft_strncmp("F", &line[i], 1) == 0)	//handle floor color
			set_floor_color(vars, line, i, fd);
		else if (ft_strncmp("C", &line[i], 1) == 0)	//handle ceiling color
			set_ceiling_color(vars, line, i, fd);
		else if (map_detected(vars, &line[i]))
			return (line);
		free_null((void **)&line);
		line = get_next_line(fd);
	}
	return (NULL);
}

void	cub_interpreter(t_vars *vars, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		fatal_error(vars, "Could not open .cub file", "open");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		fatal_error(vars, "Could not read from .cub file", "get_next_line");
	}
	line = parse_textures(vars, line, fd);
	validate_textures(vars);
	if (!line)
	{
		close(fd);
		fatal_error(vars, "No map included", "cub_interpreter");
	}
	parse_map(vars, line, fd, file);
	close(fd);
}

/* void	init_map(t_vars *vars)
{
	//get_map_size()
	parse_map(vars);
}
 */
void	init_vars(t_vars *vars)
{
	*vars = (t_vars){};
	init_player(&vars->player);
	vars->map = (t_map){};
	vars->map.no = (t_txt){};
	vars->map.so = (t_txt){};
	vars->map.we = (t_txt){};
	vars->map.ea = (t_txt){};
}

void	init_game(t_vars *vars, char *file)
{
	init_vars(vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		fatal_error(vars, "Could not initiate mlx session", "mlx_init");
	cub_interpreter(vars, file);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "cub3D");
	if (!vars->win)
		fatal_error(vars, "Could not initiate new window", "mlx_new_window");
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);	//is buffer needed or directly img?
	if (!vars->img)
		fatal_error(vars, "Could not initiate buffer image", "mlx_new_image");
	vars->img_addr = mlx_get_data_addr(vars->img, &vars->bpp, \
		&vars->size_line, &vars->endian);
	if (!vars->img_addr)
		fatal_error(vars, "Could not get memory address of image", \
		"mlx_get_data_addr");
}
