/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quanguye <quanguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:16:50 by quanguye          #+#    #+#             */
/*   Updated: 2024/08/28 18:11:53 by quanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				cost;
	bool			above_median;
	bool			cheapest;
	int				index;

	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_printf(const char *format, ...);
int		initialize_stack_a(char **argv, t_stack **stack_a, int *i);
t_stack	*create_node(int data);
void	print_list(char name, t_stack *head);
int		ft_atoi(const char *str);
void	free_stack(t_stack **head);
void	swap(t_stack **head, char name);
void	push(t_stack **head_a, t_stack **head_b, char name);
void	reverse_rotate(t_stack **head, char name);
void	rotate(t_stack **head, char name);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
int		stack_len(t_stack *stack);
bool	is_sorted(t_stack *stack);
void	push_swap(t_stack **a, t_stack **b);
void	tiny_sort(t_stack **a);
int		find_duplicates(t_stack *a);
void	turk_algorithm(t_stack **a, t_stack **b);
void	find_closest_bigger(t_stack **stack_a, t_stack **stack_b);
void	find_closest_smaller(t_stack **stack_a, t_stack **stack_b);
void	is_above_median(t_stack *stack);
void	update_stack_positions(t_stack **a, t_stack **b);
void	push_cheapest_a(t_stack **a, t_stack **b);
t_stack	*find_cheapest(t_stack *stack);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	calculate_cost_for_b(t_stack *b, t_stack *a);
void	push_cheapest_b(t_stack **a, t_stack **b);
void	free_splitted_array(char **array);
void	free_array(char **splitted_array);
void	free_stack_and_error(t_stack **head);
void	calculate_cost_for_a(t_stack **a, t_stack **b);
void	calculate_cost_for_b(t_stack *a, t_stack *b);
void	rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_separate_a(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_separate_b(t_stack **a, t_stack **b, t_stack *cheapest);
t_stack	*find_closest_bigger_element(t_stack *current,
			t_stack *stack, int *closest);
t_stack	*find_min_element(t_stack *stack);
t_stack	*find_closest_smaller_element(t_stack *current,
			t_stack *stack, int *closest);
t_stack	*find_max_element(t_stack *stack);

#endif
