/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:00:14 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/02 13:31:36 by sixshooterx      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	print_list(char name, t_stack *head)
{
	printf("Stack: %c\n", name);
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

bool	find_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;

	current = a;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->data == compare->data)
				return (true);
			compare = compare->next;
		}
		current = current->next;
	}
	return (false);
}
