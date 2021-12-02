/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:22 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/22 12:38:00 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_n(t_list **stack, char *action, int n, char *print)
{
	while (n--)
	{
		if ((ft_strnstr(action, "rotate", 8)))
			rotate(stack, print);
		else if ((ft_strnstr(action, "rev_rotate", 12)))
			rev_rotate(stack, print);
	}
}

void	push_max_min(t_list **stack_src, t_list **stack_dest, \
		char *min_or_max, char *print)
{
	int	min_max;

	min_max = 0;
	if (ft_strnstr(min_or_max, "min", 3))
		min_max = ft_stack_min_value(*stack_src);
	else if (ft_strnstr(min_or_max, "max", 3))
		min_max = ft_stack_max_value(*stack_src);
	while ((long int)(*stack_src)->content != min_max)
	{
		if (!ft_strncmp("b\n", print, 1))
			rotate(stack_src, "ra\n");
		else
			rotate(stack_src, "rb\n");
	}
	push(stack_src, stack_dest, "pb\n");
}

int	stack_isdup(t_list *stack)
{
	t_list	*ptr;

	while (stack->next != NULL)
	{
		ptr = stack->next;
		while (ptr != NULL)
		{
			if (stack->content == ptr->content)
			{
				return (1);
				break ;
			}
			ptr = ptr->next;
		}
		stack = stack->next;
	}
	return (0);
}
