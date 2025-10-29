/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:39:59 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:03:43 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, t_size n)
{
	const unsigned char	*ptr_s;

	ptr_s = (const unsigned char *)s;
	while (n > 0)
	{
		if (*ptr_s == (unsigned char)c)
			return ((void *)ptr_s);
		n--;
		ptr_s++;
	}
	return (NULL);
}
