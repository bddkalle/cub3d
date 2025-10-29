/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isin_strs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:09:03 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:05:58 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_str_isin_strs(char *needle, char **needle_box)
{
	int	i;
	int	j;

	i = 0;
	while (needle_box[i])
	{
		j = 0;
		while (needle_box[i][j] && needle_box[i][j] == needle[j])
			j++;
		if (!needle[j] && !needle_box[i][j])
			return (1);
		i++;
	}
	return (0);
}
