/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:52:38 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/13 16:31:43 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*ptr;

	ptr = (const char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
		{
			return ((char *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char* str = "ahoj";
//     char* result = ft_memchr(str, 'j', 3);
//     if (result != NULL) {
//         printf("%c", *result);
//     } else {
//         printf("Character not found\n");
//     }
//     return 0;
// }
