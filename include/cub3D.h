/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:00:52 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/13 16:26:04 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#  define WIDTH 1280
#  define HEIGHT 720
#  define BLOCK 64

#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363

#  define PI 3.14159265359

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "structs.h"

//Init
void	init_game(t_vars *vars, char *argv);

//Error
void	input_error(char *errmsg);
void	fatal_error(t_vars *vars, char *errmsg, char *fctname);

//Free
void	free_null(void **ptr);
void	free_all(t_vars *vars);

//MLX
int		close_win(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);

//Draw
void	put_pixel(t_vars *vars, int x, int y, int color);
int		draw_img(t_vars *vars);
void	draw_square(t_vars *vars, int x, int y, int size, int color);
void	cast_ray(t_vars *vars, float beta, int ray, bool draw_map);
t_wall_orient	touch(t_vars *vars, float px, float py);
void	draw_map(t_vars *vars);

//Player
void	init_player(t_player *player);
void	move_player(t_vars *vars);

//Map
void	parse_map(t_vars *vars);

//Validate
void	validate_fileformat(char *s);
void	validate_input_file(char *s);

//helper DELETE LATER
void	wall_detector_helper(t_vars *vars);


#endif
