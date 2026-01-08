/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:54:42 by fschnorr          #+#    #+#             */
/*   Updated: 2025/11/21 16:51:57 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_txt
{
	int		px_w;
	int		px_h;
	void	*img;
}	t_txt;

typedef struct s_map
{
	char	**grid;
	t_txt	no;
	t_txt	so;
	t_txt	we;
	t_txt	ea;
	int		floor[3];
	int		ceiling[3];
}	t_map;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

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