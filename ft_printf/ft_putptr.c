/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:41:38 by quanguye          #+#    #+#             */
/*   Updated: 2023/11/27 16:11:31 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer(unsigned long num)
{
	const char	*s;
	int			i;

	i = 0;
	s = "0123456789abcdef";
	if (num >= 16)
	{
		i += ft_pointer(num / 16);
		i += ft_pointer(num % 16);
	}
	else
		i += write(1, &s[num], 1);
	return (i);
}

int	ft_putptr(unsigned long pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		i += write(1, "(nil)", 5);
	else
	{
		i += write(1, "0x", 2);
		i += ft_pointer(pointer);
	}
	return (i);
}
