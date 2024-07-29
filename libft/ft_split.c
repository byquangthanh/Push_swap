/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:51:45 by sixshooterx       #+#    #+#             */
/*   Updated: 2023/11/01 10:10:25 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	insideword;

	count = 0;
	insideword = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (insideword == 0)
			{
				insideword = 1;
				count++;
			}
		}
		else
		{
			insideword = 0;
		}
		s++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static void	cleanup_memory(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
}

static char	*split_word(const char **s, char c)
{
	int		word_len;
	char	*word;
	int		j;

	word_len = word_length(*s, c);
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < word_len)
	{
		word[j] = *(*s);
		(*s)++;
		j++;
	}
	word[word_len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			ptr[i] = split_word(&s, c);
			if (!ptr[i])
			{
				cleanup_memory(ptr, i - 1);
				return (NULL);
			}
			i++;
		}
		else
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}

// void print_string_array(char **strings) {
//     while (*strings) {
//         printf("%s\n", *strings);
//         strings++;
//     }
// }

// int main() {
//     // Test case 1: Normal input with spaces as delimiters
//     char input1[] = "Hello World! Welcome to ChatGPT!";
//     char **result1 = ft_split(input1, ' ');
//     printf("Test Case 1:\n");
//     print_string_array(result1);

//     // Test case 2: Input with different delimiter
//     char input2[] = "apple,orange,banana,grape";
//     char **result2 = ft_split(input2, ',');
//     printf("\nTest Case 2:\n");
//     print_string_array(result2);

//     // Test case 3: Input with no words
//     char input3[] = "";
//     char **result3 = ft_split(input3, ' ');
//     printf("\nTest Case 3:\n");
//     print_string_array(result3);

//     // Test case 4: Input with multiple spaces between words
//     char input4[] = "  Multiple    Spaces   ";
//     char **result4 = ft_split(input4, ' ');
//     printf("\nTest Case 4:\n");
//     print_string_array(result4);

//     // Free memory allocated by ft_split
//     free(result1);
//     free(result2);
//     free(result3);
//     free(result4);

//     return 0;
// }
