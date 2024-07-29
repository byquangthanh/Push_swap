/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:04:58 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/13 16:42:14 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	ptr = (char *)malloc((end - start + 1 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start + 1))
	{
		ptr[i] = s1[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main(void)
// {
//     char str[] = "  ahoj l";
//     printf("%s", ft_strtrim(str, "l"));
//     return 0;
//}
