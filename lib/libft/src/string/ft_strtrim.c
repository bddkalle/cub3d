/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:58:14 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:09:00 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	to_trim(char const *set, char c)
{
	t_size	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	t_size	i;
	t_size	j;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	i = 0;
	while (to_trim(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && to_trim(set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - (i - 1)));
}
