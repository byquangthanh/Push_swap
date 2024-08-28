/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:09:58 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/28 18:12:08 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
