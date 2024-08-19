/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:08:14 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/19 17:11:05 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack != NULL)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

bool	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	push_swap(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		ft_printf("it is sorted");
	else if (stack_len(*a) == 2)
		swap(a, 'a');
	else if (stack_len(*a) == 3)
		tiny_sort(a);
	else
		turk_algorithm(a, b);

}

/*
THE TURK ALGORITHM
- push to stack b until there are 2 nodes in stack b
- every a node has target node from stack b
- target node is the closest smaller number to the b node
- if no closest smaller number exists the tRGET IS MAX VALUE
- find cheapest node to push
- push cost - sum x operations to bring 'a' to top + sum y operations to bring target to top
- we will then push each of the node from the stack a to stack b based on cost analysis
- once we have 3 nodes in stack a we will use tiny sort to sort them
- now we push nodes from stack_b to stack_a
	- b node has the closest bigger number to the a node as the target
	- if no closest bigger number exists the target is the min value
- median determines we RRA or RA
	- if target node a is above we will do RA
	- if target node a is below we will do RRA
	- complete with smallest number on top
*/

void	turk_algorithm(t_stack **a, t_stack **b)
{
	int	a_len;


	a_len = stack_len(*a);
	while (a_len-- > 3)
		push(b, a, 'b');
	init_a_target_nodes(a, b);
	while (stack_len(*a) != 3)
	{
		find_closest_smaller(a, b);
		calculate_cost(a, b);
		push_cheapest();
	}
}

void	push_cheapest(t_stack **a, t_stack **b)
{

}

void	update_stack_positions(t_stack **stack)
{
	t_stack	*current_stack;
	int		i;

	i = 0;
	current_stack = *stack;
	while (current_stack != NULL)
	{
		current_stack->index = i;
		i++;
		current_stack = current_stack->next;
	}
}

void	is_above_median(t_stack **stack)
{
	int		median;
	t_stack	*current_stack;

	current_stack = *stack;
	median = stack_len(current_stack) / 2;
	while(current_stack)
	{
		if (current_stack->index < median)
			current_stack->above_median = false;
		else
			current_stack->above_median = true;
		current_stack = current_stack->next;
	}
}

void	calculate_cost_for_a(t_stack **a, t_stack **b)
{
	t_stack	*current_stack;
	t_stack	*target;
	int		cost;

	current_stack = *a;
	target = *b;
	while (current_stack != NULL)
	{
		current_stack->cost = stack_len
		current_stack = current_stack->next;
	}
}

void	find_closest_bigger(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*target;
	int		closest_bigger;

	current_a = *stack_a;
	while (current_b)
	{
		target = NULL;
		closest_bigger = INT_MAX;
		current_b = *stack_b;
		while (current_a)
		{
			if (current_b < current_a
				&& current_a->data < closest_bigger)
			{
				closest_bigger = current_a->data;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (!target)
		{
			current_a = *stack_a;
			while (current_a)
			{
				if (current_a->data > current_a->next->data
					&& current_a->next->data)
					target = current_a->next;
				current_a = current_a->next;
			}
		}
		current_b->target = target;
		current_b = current_b->next;
	}
}

void	find_closest_smaller(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*target;
	int		closest_smaller;

	current_a = *stack_a;
	while (current_a)
	{
		closest_smaller = INT_MAX;
		target = NULL;
		current_b = *stack_b;
		while (current_b)
		{
			if (current_b->data < current_a->data
				&& current_b->data > closest_smaller)
			{
				closest_smaller = current_b->data;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (!target)
		{
			current_b = *stack_b;
			while (current_b)
			{
				if (!target || current_b->data > target->data)
					target = current_b;
				current_b = current_b->next;
			}
		}
		current_a->target = target;
		current_a = current_a->next;
	}
}


void	tiny_sort(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->data;
	mid = (*a)->next->data;
	bot = (*a)->next->next->data;

	if (top > mid && top > bot)
	{
		rotate(a, 'a');
		if (mid > bot)
			swap(a, 'a');
	}
	else if (mid > top && mid > bot)
	{
		reverse_rotate(a, 'a');
		if (top < bot)
			swap(a, 'a');
	}
	else if (top > mid)
		swap(a, 'a');
}
