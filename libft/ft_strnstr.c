/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:10:07 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/01 10:11:04 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle == NULL || needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
//     const char *haystack = "Hello, World!";
//     const char *needle = " ";
//     size_t len = 4; // Length of the haystack string

//     char *result = ft_strnstr(haystack, needle, len);
//     if (result != NULL)
//     {
//         printf("Needle found at index: %ld\n", result - haystack);
//     }
//     else
//     {
//         printf("Needle not found in the haystack.\n");
//     }

//     return 0;
// }
