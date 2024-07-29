/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:33:06 by quanguye          #+#    #+#             */
/*   Updated: 2024/07/29 16:18:01 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Goals:

Make two double linked lists
One will intake the arguments from th argv array
One will be empty

Create the operations
- SA : swap a - swap the first 2 elements at the top of stack a
- SB : swap b - swap the first 2 elements at the top of stack b
- SS : SA and SB at the same time

- PA : push a - take the first element at the top of b and put it at the top of a
- PB : push b - take the first element at the top of a and put it at the top of b

- RA : rotate a - shift up all elements of stack a by 1. The first element becomes the last one
- RB : rotate b - shift up all elements of stack b by 1. The first element becomes the last one
- RR : RA and RB at the same time

- RRA : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one
- RRB : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one
- RRR : RRA and RRB at the same time

Create the sorting algorithm
- Sort the stack a in ascending order

*/

#include "push_swap.h"

int	main(int ac, char *argv[])
{
	t_stack	*head;

	head = NULL;
	if (ac < 2)
	{
		printf("Usage: ./program [nums]\n");
		return (0);
	}
	initialize_stack(argv, &head);
	print_list(head);
	return (0);
}

t_stack	*create_node(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	initialize_stack(char **argv, t_stack **head)
{
	int		i;
	t_stack	*new_node;
	t_stack	*temp;

	i = 1;
	while (argv[i])
	{
		if (*head == NULL)
			*head = create_node(ft_atoi(argv[i]));
		else
		{
			new_node = create_node(ft_atoi(argv[i]));
			temp = *head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
		i++;
	}
}

void	print_list(t_stack *head)
{
	t_stack	*current;

	current = head;
	printf("Linked List: ");
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}
