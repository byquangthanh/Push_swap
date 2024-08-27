/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:08:14 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/27 18:18:06 by quanguye         ###   ########.fr       */
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

	while (a_len-- > 3 && stack_len(*b) < 2)
		push(b, a, 'b');
	while (stack_len(*a) != 3)
	{
		find_closest_smaller(a, b);
		update_stack_positions(a, b);
		calculate_cost_for_a(a);
		push_cheapest_a(a, b);
	}
	tiny_sort(a);
	find_closest_bigger(a, b);
	while (stack_len(*b) != 0)
	{
		find_closest_bigger(a, b);
		update_stack_positions(a, b);
		is_above_median(*a);
		calculate_cost_for_b(*a, *b);
		push_cheapest_b(a, b);
	}
	while (!is_sorted(*a))
		reverse_rotate(a, 'a');
}

void	push_cheapest_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		a_rotations;
	int		b_rotations;
	int		len_a;

	cheapest = find_cheapest(*b);
	len_a = stack_len(*a);
	a_rotations = cheapest->target->index;
	b_rotations = cheapest->index;
	if (cheapest->target->above_median)
	{
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
	else if (!cheapest->target->above_median)
	{
		while (b_rotations > 0)
		{
			rotate(b, 'b');
			b_rotations--;
		}
		while (a_rotations < len_a)
		{
			reverse_rotate(a, 'a');
			a_rotations++;
		}
	}
	push(a, b, 'a');
}

void	calculate_cost_for_b(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*current_target;

	current_b = b;
	current_target = current_b->target;

	while (current_b)
	{
			if (current_b->target->above_median)
				current_b->cost = (current_b->index)
					+ (current_b->target->index);
			else if (!current_b->target->above_median)
				current_b->cost = (current_b->index)
					+ (stack_len(a) - current_b->target->index);
		current_b = current_b->next;
	}
}

void	push_cheapest_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		a_rotations;
	int		b_rotations;

	cheapest = find_cheapest(*a);
	a_rotations = cheapest->index;
	b_rotations = cheapest->target->index;
	while (a_rotations > 0 && b_rotations > 0)
	{
		rotate(a, 'r');
		rotate(b, 'r');
		a_rotations--;
		b_rotations--;
	}
	while (a_rotations > 0)
	{
		rotate(a, 'a');
		a_rotations--;
	}
	while (b_rotations > 0)
	{
		rotate(b, 'b');
		b_rotations--;
	}
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

void	calculate_cost_for_a(t_stack **stack)
{
	t_stack	*current_stack;
	t_stack	*current_target;
	int		cost;

	current_stack = *stack;
	current_target = current_stack->target;

	while (current_stack != NULL)
	{
		current_stack->cost = (current_stack->index)
			+ (current_stack->target->index);
		current_stack = current_stack->next;
	}
}

void    find_closest_bigger(t_stack **stack_a, t_stack **stack_b)
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
