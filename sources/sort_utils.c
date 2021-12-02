/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:55 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/11 14:11:16 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	up_or_down(int diff, t_list *lst, int control)
{
	if (diff == 214748364)
		return (search_first(lst, ft_stack_min_value(lst)));
	if (control < (ft_lstsize(lst) - control))
		return (control);
	else
		return (control - ft_lstsize(lst));
}

int	search_num(t_list *lst, int num)
{
	t_list	*next;
	int		count;
	int		diff;
	int		control;

	count = 0;
	control = 0;
	diff = 214748364;
	if (lst != NULL)
	{
		next = lst;
		while (next != NULL)
		{
			if ((num < (long int)next->content) && \
			(((long int)next->content) - num) < diff)
			{
				diff = (long int)next->content - num;
				control = count;
			}
			count++;
			next = next->next;
		}
		return (up_or_down(diff, lst, control));
	}
	return (0);
}

float	*divide(t_list **stack_a, int division)
{
	int		max;
	int		min;
	float	divide;
	float	*arr_divide;

	arr_divide = malloc (sizeof (float) * division);
	max = ft_stack_max_value(*stack_a);
	min = ft_stack_min_value(*stack_a);
	divide = (max - min) / division;
	arr_divide[0] = divide + min;
	arr_divide[1] = arr_divide[0] + divide;
	arr_divide[2] = arr_divide[1] + divide;
	arr_divide[3] = arr_divide[2] + divide;
	arr_divide[4] = arr_divide[3] + divide + 30;
	if (division == 11)
	{
		arr_divide[5] = arr_divide[4] + divide;
		arr_divide[6] = arr_divide[5] + divide;
		arr_divide[7] = arr_divide[6] + divide;
		arr_divide[8] = arr_divide[7] + divide;
		arr_divide[9] = arr_divide[8] + divide;
		arr_divide[10] = arr_divide[9] + divide + 30;
	}
	return (arr_divide);
}

int	search_first(t_list *lst, int threshold)
{
	t_list	*next;
	int		count;

	count = 0;
	if (lst != NULL)
	{
		next = lst;
		while (next != NULL)
		{
			if ((long int)next->content <= threshold)
				return (count);
			count++;
			next = next->next;
		}
	}
	return (-1);
}

int	search_last(t_list *lst, int threshold)
{
	t_list	*next;
	int		count;
	int		control;

	control = 0;
	count = 0;
	if (lst != NULL)
	{
		next = lst;
		while (next != NULL)
		{
			if ((long int)next->content <= threshold)
				control = count;
			count++;
			next = next->next;
		}
	}
	return (ft_lstsize(lst) - control);
}
