/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:09:42 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/02 12:04:34 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

#include <stddef.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (0);
	i = 0;
	j = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	while (i + 1 < dstsize && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

// int main(void)
// {
//     char str[] = "hello";
//     char str1[] = " world";
//     int size = ft_strlcat(str, str1, 3);

//     printf("Concetated String: %s\n", str);
//     printf("Length of Copied String: %d\n", size);
//     return 0;
// }
