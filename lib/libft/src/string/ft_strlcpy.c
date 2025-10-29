/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:22:12 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:08:28 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_size	ft_strlcpy(char *dst, const char *src, t_size dstsize)
{
	t_size			src_len;
	unsigned long	j;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	j = 0;
	while (j < (dstsize - 1) && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (src_len);
}
