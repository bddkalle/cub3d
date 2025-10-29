/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:19:53 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:04:06 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, t_size n)
{
	unsigned char	*tmp_dest_ptr;
	unsigned char	*tmp_src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp_dest_ptr = (unsigned char *) dest;
	tmp_src_ptr = (unsigned char *) src;
	if (tmp_dest_ptr > tmp_src_ptr)
		while (n-- > 0)
			tmp_dest_ptr[n] = tmp_src_ptr[n];
	else
		while (n-- > 0)
			*tmp_dest_ptr++ = *tmp_src_ptr++;
	return (dest);
}
