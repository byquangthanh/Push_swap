/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:08:14 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/28 18:10:51 by quanguye         ###   ########.fr       */
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
		return ;
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
- push cost - sum x operations to bring 'a' to top +
sum y operations to bring target to top
- we will then push each of the node from the stack a
to stack b based on cost analysis
- once we have 3 nodes in stack a we will use tiny sort to sort them
- now we push nodes from stack_b to stack_a
	- b node has the closest bigger number to the a node as the target
	- if no closest bigger number exists the target is the min value
- median determines we RRA or RA
	- if target node a is above we will do RA
	- if target node a is below we will do RRA
	- complete with smallest number on top
*/

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = stack_len(*a);
	while (a_len-- > 3 && stack_len(*b) < 2)
		push(b, a, 'b');
	while (stack_len(*a) > 3)
	{
		find_closest_smaller(a, b);
		update_stack_positions(a, b);
		is_above_median(*a);
		is_above_median(*b);
		calculate_cost_for_a(a, b);
		push_cheapest_a(a, b);
	}
}

void	turk_algorithm(t_stack **a, t_stack **b)
{
	sort_stacks(a, b);
	tiny_sort(a);
	while (stack_len(*b) != 0)
	{
		find_closest_bigger(a, b);
		update_stack_positions(a, b);
		is_above_median(*a);
		is_above_median(*b);
		calculate_cost_for_b(*a, *b);
		push_cheapest_b(a, b);
	}
	while (!is_sorted(*a))
		reverse_rotate(a, 'a');
}
