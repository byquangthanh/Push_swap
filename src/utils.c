/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:00:14 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/24 17:20:07 by sixshooterx      ###   ########.fr       */
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
	int	i;

	i = 0;
	printf("Stack %c:\n", name);
	while (head != NULL)
	{
		printf("Node %d:\n", i);
		printf("  Data: %d\n", head->data);
		if (head->target)
			printf("  Target: %d\n", head->target->data);
		else
			printf("  Target: None\n");
		printf("  Index: %d\n", head->index);
		printf("  Cost: %d\n", head->cost);
		printf("  Above Median: %s\n", head->above_median ? "true" : "false");
		printf("  Cheapest: %s\n", head->cheapest ? "true" : "false");
		head = head->next;
		i++;
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

void	free_stack(t_stack **head)
{
	t_stack	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
