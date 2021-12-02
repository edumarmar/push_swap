/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:51 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/22 13:49:49 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_to_top(t_list **stack)
{
	t_list	*next;
	int		count;
	int		control;
	int		max;

	max = ft_stack_max_value(*stack);
	count = 0;
	if (*stack != NULL)
	{
		next = *stack;
		while (next != NULL)
		{
			if ((long int)next->content == max)
				control = count;
			count++;
			next = next->next;
		}
		if (control < (ft_lstsize(*stack) - control))
			action_n(stack, "rotate", control, "rb\n");
		else
			action_n(stack, "rev_rotate", ft_lstsize(*stack) - control, \
			"rrb\n");
	}
}

void	move_backtoa(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		max_to_top(stack_b);
		push(stack_b, stack_a, "pa\n");
	}
}

void	findspot_b(t_list **stack_a, t_list **stack_b)
{
	int	move_b;

	move_b = search_num(*stack_b, (long int)(*stack_a)->content);
	if (move_b >= 0)
		action_n(stack_b, "rotate", move_b, "rb\n");
	else
		action_n(stack_b, "rev_rotate", -move_b, "rrb\n");
	push(stack_a, stack_b, "pb\n");
}

void	sort_large(t_list **stack_a, t_list **stack_b, int div, int mv_last)
{
	float	*arr_interval;
	int		i;
	int		mv_fst;

	i = 0;
	arr_interval = divide(stack_a, div);
	while (i < div)
	{
		mv_fst = 0;
		while (mv_fst != -1)
		{
			mv_fst = search_first(*stack_a, arr_interval[i]);
			if (mv_fst == -1)
				break ;
			mv_last = search_last(*stack_a, arr_interval[i]);
			if (mv_fst <= mv_last)
				action_n(stack_a, "rotate", mv_fst, "ra\n");
			else if (mv_last < mv_fst)
				action_n(stack_a, "rev_rotate", mv_last, "rra\n");
			findspot_b(stack_a, stack_b);
		}
		i++;
	}
	free(arr_interval);
	move_backtoa(stack_a, stack_b);
}
