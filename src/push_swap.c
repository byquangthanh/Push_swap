/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:33:06 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/02 13:32:15 by sixshooterx      ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2 && ft_strcmp(argv[1], "") == 0)
		return (0);
	else if (ac == 2)
	{
		argv = ft_split(argv[1], ' ');
		initialize_stack_a(argv, &stack_a);
	}
	else if (ac < 2)
	{
		printf("Usage: ./push_swap [nums]\n");
		return (1);
	}
	else
		initialize_stack_a(argv + 1, &stack_a);
	if (find_duplicates(stack_a) == true)
		ft_printf("duplicate\n");
	else
		ft_printf("no duplicate\n");
	push_swap(&stack_a, &stack_b);
	print_list('a' ,stack_a);
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

int	initialize_stack_a(char **argv, t_stack **head)
{
	t_stack	*new_node;
	t_stack	*temp;

	while (*argv)
	{
		new_node = create_node(ft_atoi(*argv));
		if (new_node == NULL)
			free_stack(head);
		if (**argv < '0' || **argv > '9')
			ft_printf("Error\n");
		if (*head == NULL)
			*head = new_node;
		else
		{
			temp = *head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
		argv++;
	}
	return (1);
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
