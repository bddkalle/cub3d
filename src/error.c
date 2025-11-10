/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:14:40 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/07 15:05:48 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
		perror(fctname);
	free_all(vars);
	exit(1);
}
