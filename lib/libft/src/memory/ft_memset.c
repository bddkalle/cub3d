/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:04:30 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:04:13 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *s, int c, t_size n)
{
	unsigned char		*tmp_ptr;
	long unsigned int	i;

	tmp_ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		tmp_ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
