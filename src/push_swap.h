/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:16:50 by quanguye          #+#    #+#             */
/*   Updated: 2024/07/29 17:10:45 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


int		ft_printf(const char *format, ...);
int		initialize_stack_a(char **argv, t_stack **head);
t_stack	*create_node(int data);
void	print_list(t_stack *head);
int		ft_atoi(const char *str);
void	free_stack(t_stack **head);
void	swap(t_stack **head);
void	push(t_stack **head_a, t_stack **head_b);
void	reverse_rotate(t_stack **head);
void	rotate(t_stack **head);

#endif
