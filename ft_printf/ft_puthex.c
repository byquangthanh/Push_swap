/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:59:59 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/27 15:42:31 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(long num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	else if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static char	*hex_itoa(long num, const char capital)
{
	char	*str;
	int		len;
	char	*symbols;
	char	*symbolsdown;

	len = hex_len(num);
	symbols = "0123456789ABCDEF";
	symbolsdown = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (num < 0)
		num = -num;
	else if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num)
	{
		if (capital == 'x')
			str[--len] = symbolsdown[num % 16];
		else if (capital == 'X')
			str[--len] = symbols[num % 16];
		num = num / 16;
	}
	return (str);
}

int	ft_puthex(long n, const char capital)
{
	int		len;
	char	*num;

	len = 0;
	num = hex_itoa(n, capital);
	len = ft_putstr(num);
	free(num);
	return (len);
}

// int	ft_puthex(long num, const char capital)
// {
// 	char* symbols;
// 	char* symbolsdown;
// 	char* ptr;

// 	ptr = malloc()

// 	symbols 	= "123456789ABCDEF";
// 	symbolsdown = "123456789abcdef";
// 	if (num < 0)
// 	{
// 		ft_puthex(-num, capital);
// 	}
// 	if (num < 16)
// 	{
// 		if (capital == 'X')
// 			write(1, &symbols[--num], 1);
// 		if (capital == 'x')
// 			write(1, &symbolsdown[--num], 1);
// 	}
// 	else if (num >= 16)
// 	{
// 		ft_puthex(num / 16, capital);
// 		ft_puthex(num % 16, capital);
// 	}
// 	return (1);
// }

// int main(void)
// {
// 	int i = -12;

// 	ft_puthex(12, 'X');
// 	return 0;
// }
