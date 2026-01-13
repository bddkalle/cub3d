
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

void	parse_color(t_vars *vars, char *line, int fd, char **color_arr)
{
	int		i;
	int		j;
	long	color;

	j = 0;
	while (j < 3)
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
		j++;
	}
	j = 0;
	while (j < 3)
	{	
		color = ft_atol(color_arr[j]);			//vllt ohne color var?
		if (!(color >= 0 && color <= 255))
			parse_color_error(vars, line, fd, color_arr);
		vars->map.floor[j++] = color;
	}
}
