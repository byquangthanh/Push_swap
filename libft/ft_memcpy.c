/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:09:13 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/10/31 22:41:56 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	size_t				i;

	ptr = dst;
	ptr2 = src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (ptr);
}
