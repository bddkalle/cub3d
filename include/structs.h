/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:54:42 by fschnorr          #+#    #+#             */
/*   Updated: 2026/01/15 20:14:21 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_map
{
	char	**grid;
	t_txt	no;
	t_txt	so;
	t_txt	we;
	t_txt	ea;
	int		floor[4];
	int		ceiling[4];
}	t_map;

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
	int		offset;
	float	distance;
	float	wall_height;
	int		wall_bottom;
	int		wall_top;
} t_touch;

typedef struct s_player
{
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
