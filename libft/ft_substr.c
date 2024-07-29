/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:10:12 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/02 12:47:09 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)malloc((len + 1) * sizeof(*s));
	i = 0;
	j = 0;
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

// int main(void)
// {
//     char str[] = "Hello Bro";
//     printf("%s", ft_substr(str, 2, 9));
// }
