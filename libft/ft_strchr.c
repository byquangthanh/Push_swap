/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:09:20 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/13 15:55:50 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
//unsigned char because were not working with negative bytes
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	target;

	i = 0;
	target = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == target)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (target == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

// int main() {
//     const char *text = "Hello, World!";
//     char target = 'o';
//     char *result = ft_strchr(text, target);
//     if (result != NULL) {
//         printf("Found '%c' at position: %ld\n", target, result - text + 1);
//     } else {
//         printf("'%c' not found in the string.\n", target);
//     }

//     return 0;
// }
