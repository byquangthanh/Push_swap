/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:35:32 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/01 10:48:01 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 10)
	{
		n += '0';
		write(fd, &n, 1);
	}
}

// int main(void)
// {
// 	// ft_putnbr_fd(-2147483648, 1);
// 	ft_putnbr_fd(2, 1);
// 	ft_putnbr_fd(-2, 1);
// 	// ft_putnbr_fd(2, 1);
// 	return 0;
// }
