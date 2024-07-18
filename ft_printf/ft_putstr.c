/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:19:57 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/27 15:42:48 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (str == NULL)
	{
		return (0);
	}
	if (*str == '\0')
	{
		return (0);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	char * str = "ahoj";
// 	ft_putstr(str);
// 	return 1;
// }
