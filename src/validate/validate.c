/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:15:55 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/20 14:34:15 by fschnorr         ###   ########.fr       */
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
		"NO: load_no_textures");
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
		"SO: load_so_textures");
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
		"WE: load_we_textures");
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
		"EA: load_ea_textures");
	}
}

void	validate_fileformat(char *s)
{
	int	l;

	l = ft_strlen(s) - 1;
	if (s[l] != 'b' && s[l - 1] != 'u' && s[l - 2] != 'c' && s[l - 3] != '.')
		input_error("Invalid fileformat - .cub file expected");
}
