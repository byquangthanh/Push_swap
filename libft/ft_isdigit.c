/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:09:09 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/10/30 16:08:31 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_isdigit(49));
//     printf("%d\n", ft_isdigit(60));
//     return 0;
// }
