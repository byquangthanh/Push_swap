/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:55:33 by quanguye          #+#    #+#             */
/*   Updated: 2023/11/27 15:58:17 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	itoa_len(long long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	else if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	long long		num;
	int				len;

	num = n;
	len = itoa_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	else if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

int	ft_putunsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_putstr(num);
		free(num);
	}
	return (print_length);
}
