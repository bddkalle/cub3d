/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:24:01 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:04:01 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, t_size n)
{
	unsigned char		*tmp_ptr;
	const unsigned char	*tmp_src;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	tmp_ptr = (unsigned char *)dest;
	tmp_src = (const unsigned char *)src;
	while (n > 0)
	{
		*tmp_ptr = *tmp_src;
		tmp_ptr++;
		tmp_src++;
		n--;
	}
	return (dest);
}
