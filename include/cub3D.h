/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:00:52 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/31 16:19:13 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#  define WIDTH 1280
#  define HEIGHT 720

#  define W 119
#  define A 97
#  define S 115
#  define D 100

#  define PI 3.14159265359

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "structs.h"

//Init
void	init_game(t_vars *vars);

//Error
void	fatal_error(t_vars *vars, char *errmsg, char *fctname);

//Free
void	free_all(t_vars *vars);

//MLX
int		close_win(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);

//Draw
int		draw_img(t_vars *vars);
void	draw_square(t_vars *vars, int x, int y, int size, int color);

//Player
void	init_player(t_player *player);
void	move_player(t_player *player);


#endif