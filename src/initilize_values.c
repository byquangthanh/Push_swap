/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:07:39 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/28 18:08:26 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
