/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:33:06 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/28 16:54:01 by quanguye         ###   ########.fr       */
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

void	handle_error(t_stack **stack_a, char **splitted_nums)
{
	if (*stack_a)
		free_stack(stack_a);
	if (splitted_nums)
		free_array(splitted_nums);
	exit(1);
}

int	handle_input(int ac, char **argv, t_stack **stack_a, char ***splitted_nums)
{
	int	i;

	i = 0;
	if (ac == 2 && ft_strcmp(argv[1], "") == 0)
		return (0);
	if (ac < 2)
	{
		printf("Usage: ./push_swap [nums]\n");
		exit(1);
	}
	if (ac == 2)
	{
		*splitted_nums = ft_split(argv[1], ' ');
		initialize_stack_a(*splitted_nums, stack_a, &i);
	}
	else
		initialize_stack_a(argv + 1, stack_a, &i);
	if (i == 1)
	{
		ft_printf("Error");
		handle_error(stack_a, *splitted_nums);
		exit(1);
	}
	return (1);
}

int	main(int ac, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted_nums;

	stack_a = NULL;
	stack_b = NULL;
	splitted_nums = NULL;
	if (!handle_input(ac, argv, &stack_a, &splitted_nums))
		return (0);
	if (find_duplicates(stack_a))
		handle_error(&stack_a, splitted_nums);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	if (splitted_nums)
		free_array(splitted_nums);
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
	new_node->target = NULL;
	new_node->cost = 0;
	new_node->index = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	return (new_node);
}

int	initialize_stack_a(char **argv, t_stack **stack_a, int *i)
{
	t_stack	*new_node;
	t_stack	*temp;

	while (*argv)
	{
		if (ft_atoi(*argv) == 0 && ft_strcmp(*argv, "0") != 0)
			*i = 1;
		new_node = create_node(ft_atoi(*argv));
		if (new_node == NULL)
			free_stack(stack_a);
		if (*stack_a == NULL)
			*stack_a = new_node;
		else
		{
			temp = *stack_a;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
		argv++;
	}
	return (1);
}

void	free_array(char **splitted_array)
{
	int	i;

	if (splitted_array == NULL)
		return ;
	i = 0;
	while (splitted_array[i])
	{
		free(splitted_array[i]);
		i++;
	}
	free(splitted_array);
}
