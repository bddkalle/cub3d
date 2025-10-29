/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:12:58 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:08:01 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned char	*tmp;
	int				s1_len;
	int				i;

	s1_len = ft_strlen(s1);
	tmp = (unsigned char *)malloc((s1_len + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return ((char *)tmp);
}
