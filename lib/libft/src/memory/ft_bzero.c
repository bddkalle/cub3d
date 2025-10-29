/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:02 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:03:36 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, t_size n)
{
	unsigned char		*tmp_ptr;
	long unsigned int	i;

	tmp_ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		tmp_ptr[i] = '\0';
		i++;
	}
}
