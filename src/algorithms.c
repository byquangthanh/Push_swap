/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sixshooterx <sixshooterx@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:08:14 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/02 13:30:10 by sixshooterx      ###   ########.fr       */
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
	if (stack_len(*a) == 2)
		swap(a, 'a');
	else if (stack_len(*a) == 3)
		tiny_sort(a);

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
