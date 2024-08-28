/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:07:23 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/28 18:11:03 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char name)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*stack = second;
	if (name == 'a')
		ft_printf("sa\n");
	else if (name == 'b')
		ft_printf("sb\n");
	else
		ft_printf("ss\n");
}

void	push(t_stack **stack_dest, t_stack **stack_src, char name)
{
	t_stack	*temp;

	if (*stack_src == NULL)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	temp->next = *stack_dest;
	temp->prev = NULL;
	if (*stack_dest)
		(*stack_dest)->prev = temp;
	*stack_dest = temp;
	if (name == 'a')
		ft_printf("pa\n");
	else if (name == 'b')
		ft_printf("pb\n");
}

void	rotate(t_stack **stack, char name)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (name == 'a')
		ft_printf("ra\n");
	else if (name == 'b')
		ft_printf("rb\n");
	else if (name == 'r')
		ft_printf("rr\n");
}

void	reverse_rotate(t_stack **stack, char name)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	second_last->next = NULL;
	*stack = last;
	if (name == 'a')
		ft_printf("rra\n");
	else if (name == 'b')
		ft_printf("rrb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'n');
	rotate(b, 'n');
	ft_printf("rr\n");
}
