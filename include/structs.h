/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:54:42 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/31 16:23:11 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_player
{
	float	x;
	float	y;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
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
}	t_vars;

#endif