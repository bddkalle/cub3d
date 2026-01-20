/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:00:52 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/20 09:39:51 by vboxuser         ###   ########.fr       */
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
#  define INT_MAX 2147483647

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
void	load_no_textures(t_vars *vars, char *line, int i, int fd);
void	load_so_textures(t_vars *vars, char *line, int i, int fd);
void	load_we_textures(t_vars *vars, char *line, int i, int fd);
void	load_ea_textures(t_vars *vars, char *line, int i, int fd);
void	set_floor_color(t_vars *vars, char *line, int i, int fd);
void	set_ceiling_color(t_vars *vars, char *line, int i, int fd);
void	parse_floor_color(t_vars *vars, char *line, int fd, char **color_arr);
void	parse_ceiling_color(t_vars *vars, char *line, int fd, char **color_arr);
int		ft_count_c(char c, char *str);
int		valid_c(char *s);
void	set_img_addr(t_vars *vars, char *line, int fd, t_txt *txt);

//Error
void	input_error(char *errmsg);
void	fatal_error(t_vars *vars, char *errmsg, char *fctname);
void	parse_color_error(t_vars *vars, char *line, int fd, char **color_arr);

//Free
void	free_null(void **ptr);
void	free_all(t_vars *vars);
void	free_incomplete_grid(t_vars *vars, t_point grid_pos);

//MLX
int		close_win(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);

//Draw
void	put_pixel(t_vars *vars, int x, int y, int color);
int		draw_img(t_vars *vars);
void	draw_square(t_vars *vars, int x, int y, int size, int color);
void	draw_map(t_vars *vars);
int		create_rgb(int	rgb[3]);

//Raycaster
void	cast_ray(t_vars *vars, float beta, int ray_id, bool draw_map);
bool	touch(t_vars *vars, float px, float py);
int		get_color_from_txt(t_vars *vars, t_touch *wall_slice, int y);
void	wall_detector_helper(t_vars *vars);

//Projection
float	distance(float dx, float dy);
float	correct_distance(t_vars *vars, float dist_d, float beta);
void	wall_projection(t_touch *touch);
void	wall_info(t_vars *vars, t_touch *wall_slice, float px, float py, float beta);

//Player
void	init_player(t_player *player);
void	move_player(t_vars *vars);
void	set_player(t_vars *vars, t_point p);

//Map
void	parse_map(t_vars *vars, char *line, int fd, char *file);
int		map_detected(t_vars *vars, char *s);
int		init_grid(t_vars *vars, char *map_begin, char **line2, char *file);
void	fill_grid(t_vars *vars, int fd2, char *map_begin, t_point grid_pos);
void	alloc_line(t_vars *vars, t_point p, char *line, int fd2);
void	fill_grid_row(t_vars *vars, t_point grid_pos, char *line, int fd2);

//Validate
void	validate_fileformat(char *s);
void	validate_no(t_vars *vars, char *line, int fd);
void	validate_so(t_vars *vars, char *line, int fd);
void	validate_we(t_vars *vars, char *line, int fd);
void	validate_ea(t_vars *vars, char *line, int fd);
void	validate_textures(t_vars *vars);
void	validate_f(t_vars *vars, char *line, int fd);
void	validate_c(t_vars *vars, char *line, int fd);
int		valid_map_chars(t_tile_type tile);
void	validate_map(t_vars *vars);
int		wall_check(t_vars *vars);

//Debug
void	print_grid(t_vars *vars);

#endif
