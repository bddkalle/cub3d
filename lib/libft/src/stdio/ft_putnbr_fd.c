/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:09:55 by fschnorr          #+#    #+#             */
/*   Updated: 2025/10/29 15:04:31 by fschnorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
		count += ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			count += ft_putnbr_fd(n / 10, fd);
			count += ft_putnbr_fd(n % 10, fd);
		}
		else
			count += ft_putchar_fd((n + '0'), fd);
	}
	return (count);
}
