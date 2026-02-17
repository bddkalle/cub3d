/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:54:42 by fschnorr          #+#    #+#             */
/*   Updated: 2026/02/17 14:41:51 by vboxuser         ###   ########.fr       */
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

typedef struct s_fpoint
{
	double	x;
	double	y;
}	t_fpoint;

typedef enum e_wall
{
	UNDET,
	NOTOUCH,
	TOUCH,
}	t_wall;

typedef enum e_orient
{
	HORIZONTAL,
	VERTICAL,
}	t_orient;

typedef struct s_intrsec
{
	t_orient	orient;
	t_wall		touch;
	t_fpoint	touchpoint;
	t_txt		*txt;
	int			offset;
	double		distance;
	double		wall_height;
	int			wall_bottom;
	int			wall_top;
}	t_intrsec;

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
