/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:51:02 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/11 10:51:03 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if ((long int)stack->content > (long int)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_lst_is_backsorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_stack_max_value(t_list *stack)
{
	long int	max_value;
	t_list		*tmp;

	tmp = stack;
	max_value = (long int)tmp->content;
	while (tmp)
	{
		if ((long int)tmp->content > max_value)
			max_value = (long int)tmp->content;
		tmp = tmp->next;
	}
	return (max_value);
}

int	ft_stack_min_value(t_list *stack)
{
	long int	min_value;
	t_list		*tmp;

	tmp = stack;
	min_value = (long int)tmp->content;
	while (tmp)
	{
		if ((long int)tmp->content < min_value)
			min_value = (long int)tmp->content;
		tmp = tmp->next;
	}
	return (min_value);
}

void	deletelist(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}
