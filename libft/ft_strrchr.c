/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:10:11 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/01 11:25:11 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	target;

	i = 0;
	target = (unsigned char) c;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == target)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
// int main() {
//     const char *text = "Hello, World!";
//     char target = 'o';

//     char *result = ft_strrchr(text, target);

//     if (result != NULL) {
//         printf("Found '%c' at position: %ld\n", target, result - text + 1);
//     } else {
//         printf("'%c' not found in the string.\n", target);
//     }

//     return 0;
// }
