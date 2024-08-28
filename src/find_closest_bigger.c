/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_bigger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:05:03 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/28 18:11:41 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_closest_bigger(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	int		closest_bigger;

	current_b = *stack_b;
	while (current_b)
	{
		target = find_closest_bigger_element(current_b, *stack_a,
				&closest_bigger);
		if (!target)
			target = find_min_element(*stack_a);
		current_b->target = target;
		current_b = current_b->next;
	}
}

t_stack	*find_closest_bigger_element(t_stack *current,
	t_stack *stack, int *closest)
{
	t_stack	*target;

	target = NULL;
	*closest = INT_MAX;
	while (stack)
	{
		if (current->data < stack->data && stack->data < *closest)
		{
			*closest = stack->data;
			target = stack;
		}
		stack = stack->next;
	}
	return (target);
}

t_stack	*find_min_element(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 'n');
	reverse_rotate(b, 'n');
	ft_printf("rrr\n");
}
