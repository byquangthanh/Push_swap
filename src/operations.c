/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:07:23 by sixshooterx       #+#    #+#             */
/*   Updated: 2024/08/06 15:30:42 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char name)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (name == 'a')
		ft_printf("SA\n");
	else if (name == 'b')
		ft_printf("SB\n");
	else
		ft_printf("SS\n");
}

void	push(t_stack **stack_a, t_stack **stack_b, char name)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (name == 'a')
		ft_printf("PA\n");
	else if (name == 'b')
		ft_printf("PB\n");
}

void	rotate(t_stack **stack, char name)
{
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->next = NULL;
	if (name == 'a')
		ft_printf("RA\n");
	else if (name == 'b')
		ft_printf("RB\n");
	else
		ft_printf("RR\n");
}

void	reverse_rotate(t_stack **stack, char name)
{
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	if (name == 'a')
		ft_printf("RRA\n");
	else if (name == 'b')
		ft_printf("RRB\n");
	else
		ft_printf("RRR\n");
}
