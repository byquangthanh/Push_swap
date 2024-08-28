/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:01:40 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/28 18:04:35 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_closest_smaller(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*target;
	int		closest_smaller;

	current_a = *stack_a;
	while (current_a)
	{
		target = find_closest_smaller_element(current_a,
				*stack_b, &closest_smaller);
		if (!target)
			target = find_max_element(*stack_b);
		current_a->target = target;
		current_a = current_a->next;
	}
}

t_stack	*find_closest_smaller_element(t_stack *current,
	t_stack *stack, int *closest)
{
	t_stack	*target;

	target = NULL;
	*closest = INT_MIN;
	while (stack)
	{
		if (stack->data < current->data && stack->data > *closest)
		{
			*closest = stack->data;
			target = stack;
		}
		stack = stack->next;
	}
	return (target);
}

t_stack	*find_max_element(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->data > max->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
