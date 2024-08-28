/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:08:14 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/28 17:23:25 by quanguye         ###   ########.fr       */
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
		// ft_printf("it is sorted");
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
	while (a_len-- > 3 && stack_len(*b) < 2)
		push(b, a, 'b');
	while (stack_len(*a) != 3)
	{
		find_closest_smaller(a, b);
		update_stack_positions(a, b);
		is_above_median(*a);
		is_above_median(*b);
		calculate_cost_for_a(a, b);
		push_cheapest_a(a, b);
	}
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

void	above_median_operations(t_stack **a, t_stack **b, t_stack **cheapest)
{
	int		a_rotations;
	int		b_rotations;
	int		len_a;
	t_stack	*current_cheapest;

	current_cheapest = *cheapest;
	len_a = stack_len(*a);
	a_rotations = current_cheapest->target->index;
	b_rotations = current_cheapest->index;
	while (b_rotations > 0 && a_rotations > 0)
	{
		rr(a, b);
		a_rotations--;
		b_rotations--;
	}
	while (b_rotations > 0)
	{
		rotate(b, 'b');
		b_rotations--;
	}
	while (a_rotations > 0)
	{
		rotate(a, 'a');
		a_rotations--;
	}
}

void	push_cheapest_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both_b(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both_b(a, b, cheapest);
	else
		rotate_separate_b(a, b, cheapest);
	push(a, b, 'a');
}

void	calculate_cost_for_b(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	int		len_a;
	int		len_b;

	current_b = b;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (current_b)
	{
		if (current_b->above_median)
			current_b->cost = current_b->index;
		else
			current_b->cost = len_b - current_b->index;
		if (current_b->target->above_median)
			current_b->cost += current_b->target->index;
		else
			current_b->cost += len_a - current_b->target->index;
		current_b = current_b->next;
	}
}
void	push_cheapest_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both_a(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both_a(a, b, cheapest);
	else
		rotate_separate_a(a, b, cheapest);
	push(b, a, 'b');
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*current;

	cheapest = stack;
	current = stack;
	while (current != NULL)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

void	is_above_median(t_stack *stack)
{
	int		stack_size;
	int		i;
	t_stack	*current;

	stack_size = stack_len(stack);
	i = 0;
	current = stack;
	while (current)
	{
		if (i < stack_size / 2)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

void	update_stack_positions(t_stack **a, t_stack **b)
{
	t_stack	*current_stack_a;
	t_stack	*current_stack_b;
	int		i;

	i = 0;
	current_stack_a = *a;
	current_stack_b = *b;
	while (current_stack_a != NULL)
	{
		current_stack_a->index = i;
		i++;
		current_stack_a = current_stack_a->next;
	}
	i = 0;
	while (current_stack_b != NULL)
	{
		current_stack_b->index = i;
		i++;
		current_stack_b = current_stack_b->next;
	}
}

void	calculate_cost_for_a(t_stack **a, t_stack **b)
{
	t_stack	*current_a;
	int		len_a;
	int		len_b;

	current_a = *a;
	len_a = stack_len(*a);
	len_b = stack_len(*b);
	while (current_a)
	{
		if (current_a->above_median)
			current_a->cost = current_a->index;
		else
			current_a->cost = len_a - current_a->index;
		if (current_a->target->above_median)
			current_a->cost += current_a->target->index;
		else
			current_a->cost += len_b - current_a->target->index;
		current_a = current_a->next;
	}
}


void	find_closest_bigger(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*target;
	int		closest_bigger;

	current_b = *stack_b;
	while (current_b)
	{
		target = NULL;
		closest_bigger = INT_MAX;
		current_a = *stack_a;
		while (current_a)
		{
			if (current_b->data < current_a->data
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
			target = current_a;
			while (current_a)
			{
				if (current_a->data < target->data)
					target = current_a;
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
		closest_smaller = INT_MIN;
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

void	rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	while (*a != cheapest)
		rotate(a, 'a');
	while (*b != cheapest->target)
		rotate(b, 'b');
}

void	rev_rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	while (*a != cheapest)
		reverse_rotate(a, 'a');
	while (*b != cheapest->target)
		reverse_rotate(b, 'b');
}

void	rotate_separate_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->above_median)
		while (*a != cheapest)
			rotate(a, 'a');
	else
		while (*a != cheapest)
			reverse_rotate(a, 'a');
	if (cheapest->target->above_median)
		while (*b != cheapest->target)
			rotate(b, 'b');
	else
		while (*b != cheapest->target)
			reverse_rotate(b, 'b');
}

void	rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rr(a, b);
	while (*b != cheapest)
		rotate(b, 'b');
	while (*a != cheapest->target)
		rotate(a, 'a');
}

void	rev_rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rrr(a, b);
	while (*b != cheapest)
		reverse_rotate(b, 'b');
	while (*a != cheapest->target)
		reverse_rotate(a, 'a');
}

void	rotate_separate_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->above_median)
		while (*b != cheapest)
			rotate(b, 'b');
	else
		while (*b != cheapest)
			reverse_rotate(b, 'b');
	if (cheapest->target->above_median)
		while (*a != cheapest->target)
			rotate(a, 'a');
	else
		while (*a != cheapest->target)
			reverse_rotate(a, 'a');
}
