/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:08:54 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/09/08 16:27:31 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	sum;
	int			neg;

	neg = 1;
	sum = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	if (!(str[i] <= '9' && str[i] >= '0') && str[i] != '\0')
		return (0);
	return (sum * neg);
}

// int main(void)
// {
//     printf("%d", atoi("d+2212202"));
//     return 0;
// }
