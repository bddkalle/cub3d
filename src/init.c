/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:55:06 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/10 12:10:43 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	cub_interpreter(t_vars *vars, char *file)
{
	int		fd;
	char	*line;
	char	*filename;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		fatal_error(vars, "Could not open .cub file", "open");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		fatal_error(vars, "Could not read from .cub file", "get_next_line");
	}
	while (line)
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (ft_strncmp("NO", &line[i], 2) == 0)	//handle North texture
		{
			printf("%s", &line[i]);
			i += 2;
			filename = ft_strtrim(&line[i], " \n");
			if (!filename)
			{
				close(fd);
				free_null((void **)&line);
				get_next_line(-1);
				fatal_error(vars, "Could not trim path to texture", \
				"ft_strtrim");
			}
			printf("path: %s.\n", filename);
/* 			vars->map.no.img = mlx_xpm_file_to_image(vars->mlx, filename, \
			&vars->map.no.px_w, &vars->map.no.px_h);
 */			if (!vars->map.no.img)												//weiter: free_all img includen&testen
			{
				
				close(fd);
				free_null((void **)&line);
				free_null((void **)&filename);
				get_next_line(-1);
				fatal_error(vars, "Could not create north texture", \
			"mlx_xpm_file_to_image");			
			}
			free_null((void **)&filename);
		}
		free_null((void **)&line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_map(t_vars *vars)
{
	//get_map_size()
	parse_map(vars);
}

void	init_vars(t_vars *vars)
{
	*vars = (t_vars){};
	init_player(&vars->player);
	vars->map = (t_map){};
	vars->map.no = (t_txt){};
}

void	init_game(t_vars *vars, char *file)
{
	init_vars(vars);
	cub_interpreter(vars, file);
	init_map(vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		fatal_error(vars, "Could not initiate mlx session", "mlx_init");
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
