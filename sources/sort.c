/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:59 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/11 14:08:37 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 100)
		sort_large(stack_a, stack_b, 5, 0);
	else
		sort_large(stack_a, stack_b, 11, 0);
}

void	sort_three(t_list **stack)
{
	int	max;
	int	min;

	max = ft_stack_max_value(*stack);
	min = ft_stack_min_value(*stack);
	while (!ft_lst_is_sorted(*stack))
	{
		if ((long int)(*stack)->content == max)
			rotate((stack), "ra\n");
		else if (((long int)(*stack)->content == min && \
		(long int)(*stack)->next->content == max) ||
		((long int)(*stack)->next->content == max && \
		(long int)(*stack)->next->next->content == min))
			rev_rotate((stack), "rra\n");
		else if ((long int)(*stack)->next->content == min && \
		(long int)(*stack)->next->next->content == max)
			swap((stack), ft_lstsize(*stack), "sa\n");
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_max_min(stack_a, stack_b, "min", "b\n");
	if (ft_lstsize(*stack_a) > 3)
		push_max_min(stack_a, stack_b, "min", "b\n");
	sort_three(stack_a);
	push(stack_b, stack_a, "pa\n");
	push(stack_b, stack_a, "pa\n");
}
