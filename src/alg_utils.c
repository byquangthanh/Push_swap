/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:08:52 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/28 18:09:49 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
