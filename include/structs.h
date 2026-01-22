/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:54:42 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/20 20:07:55 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "../lib/libft/includes/libft.h"

typedef struct s_txt
{
	int		px_w;
	int		px_h;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_txt;

typedef enum e_tile
{
	FLOOR = '0',
	WALL = '1',
	NORTH_SP = 'N',
	SOUTH_SP = 'S',
	EAST_SP = 'E',
	WEST_SP = 'W',
	SPACE = ' '
}	t_tile_type;

typedef struct s_tile
{
	t_tile_type	type;
	int			visited;
}				t_tile;

typedef struct s_map
{
	char	**grid;
	t_tile	**tile;
	t_size	g_h;
	t_size	g_w;
	t_txt	no;
	t_txt	so;
	t_txt	we;
	t_txt	ea;
	int		floor[4];
	int		ceiling[4];
	int		start_found;
	int		pixel_per_grid;
}	t_map;

typedef struct s_point
{
	t_size	px_x;
	t_size	px_y;
}	t_point;

typedef enum s_wall
{
	FALSE,
	NORTH,
	EAST,
	SOUTH,
	WEST,
}	t_wall;

typedef struct s_touch
{
	t_wall	wall_orient;
	t_txt	*txt;
	int		offset;
	float	distance;
	float	wall_height;
	int		wall_bottom;
	int		wall_top;
}	t_touch;

typedef struct s_player
{
	t_point	start;
	float	x;
	float	y;
	float	alpha;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;

	char		*img_addr;
	int			bpp;
	int			size_line;
	int			endian;

	t_player	player;
	t_map		map;
}	t_vars;

#endif
