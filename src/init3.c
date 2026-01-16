
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

void	set_ceiling_color(t_vars *vars, char *line, int i, int fd)
{
	char	**color_arr;

	validate_c(vars, line, fd);
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	if (!valid_c(&line[i]) || ft_count_c(',', &line[i]) != 2)
	{
		close(fd);
		free_null((void **)&line);
		get_next_line(-1);
		fatal_error(vars, "Invalid color number format", "set_ceiling_color");
	}
	color_arr = ft_split(&line[i], ',');
	parse_ceiling_color(vars, line, fd, color_arr);
	free_null((void **)&color_arr[0]);
	free_null((void **)&color_arr[1]);
	free_null((void **)&color_arr[2]);
	free_null((void **)&color_arr);
	vars->map.ceiling[3] += 1;
}

int	valid_c(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s) || *s == ' ' || *s == ',' || *s == '\n')
			s++;
		else
			return (0);
	}
	return (1);
}

int	ft_count_c(char c, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

void	parse_ceiling_color(t_vars *vars, char *line, int fd, char **color_arr)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 3)
	{
		i = 0;
		while (ft_isspace(color_arr[j][i]))
			i++;
		if (!ft_isdigit(color_arr[j][i]))
			parse_color_error(vars, line, fd, color_arr);
		while (ft_isdigit(color_arr[j][i]))
			i++;
		while (ft_isspace(color_arr[j][i]))
			i++;
		if (color_arr[j][i] != '\0')
			parse_color_error(vars, line, fd, color_arr);
	}
	j = -1;
	while (++j < 3)
	{
		if (!(ft_atol(color_arr[j]) >= 0 && ft_atol(color_arr[j]) <= 255))
			parse_color_error(vars, line, fd, color_arr);
		vars->map.ceiling[j] = ft_atol(color_arr[j]);
	}
}

void	parse_floor_color(t_vars *vars, char *line, int fd, char **color_arr)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 3)
	{
		i = 0;
		while (ft_isspace(color_arr[j][i]))
			i++;
		if (!ft_isdigit(color_arr[j][i]))
			parse_color_error(vars, line, fd, color_arr);
		while (ft_isdigit(color_arr[j][i]))
			i++;
		while (ft_isspace(color_arr[j][i]))
			i++;
		if (color_arr[j][i] != '\0')
			parse_color_error(vars, line, fd, color_arr);
	}
	j = -1;
	while (++j < 3)
	{
		if (!(ft_atol(color_arr[j]) >= 0 && ft_atol(color_arr[j]) <= 255))
			parse_color_error(vars, line, fd, color_arr);
		vars->map.floor[j] = ft_atol(color_arr[j]);
	}
}
