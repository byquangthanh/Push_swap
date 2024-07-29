/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:10:13 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/13 17:23:20 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char			*str;
	long long		num;
	int				len;

	num = n;
	len = itoa_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
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

// int main(int argc, const char *argv[])
// {
//     printf("%s\n", ft_itoa(-1000451));
// 	printf("%s\n", ft_itoa(-1));
// 	printf("%s\n", ft_itoa(-9));
//     printf("%s\n", ft_itoa(10001));
//     printf("%s\n", ft_itoa(0));
//     printf("%s", ft_itoa(-2147483648));
//     return 0;
// }
