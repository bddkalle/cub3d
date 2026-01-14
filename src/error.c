/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:14:40 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/09 17:03:07 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	parse_color_error(t_vars *vars, char *line, int fd, char **color_arr)
{
	close(fd);
	free_null((void **)&line);
	get_next_line(-1);
	free_null((void **)&color_arr[0]);
	free_null((void **)&color_arr[1]);
	free_null((void **)&color_arr[2]);
	free_null((void **)&color_arr);
	fatal_error(vars, "Incorrect color number format", \
	"parse_color");
}

void	input_error(char *errmsg)
{
	write(STDERR_FILENO, "cub3D: ", 7);
	write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	fatal_error(t_vars *vars, char *errmsg, char *fctname)
{
	if (!errno)
	{
		write(STDERR_FILENO, "cub3D: ", 7);
		write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		perror(fctname);
		write(STDERR_FILENO, errmsg, ft_strlen(errmsg));
		write(STDERR_FILENO, "\n", 1);
	}
	free_all(vars);
	exit(1);
}
