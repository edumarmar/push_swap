/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:38 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/11 10:50:39 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **stack_1, t_list **stack_2, char *print)
{
	t_list	*tmp;

	ft_putstr_fd(print, 1);
	if (*stack_1 == NULL)
		return (0);
	tmp = *stack_1;
	*stack_1 = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_2, tmp);
	return (1);
}

int	swap(t_list **stack, int len, char *print)
{
	t_list	*tmp;
	t_list	*swp;

	ft_putstr_fd(print, 1);
	if (len < 2)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	swp = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = swp;
	return (1);
}

int	rotate(t_list **stack, char *print)
{
	t_list	*tmp;
	t_list	*swp;

	ft_putstr_fd(print, 1);
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	swp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	*stack = swp->next;
	swp->next = NULL;
	tmp->next = swp;
	return (1);
}

int	rev_rotate(t_list **stack, char *print)
{
	t_list	*tmp;
	t_list	*swp;

	ft_putstr_fd(print, 1);
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = *stack;
	swp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	*stack = tmp->next;
	tmp->next->next = swp;
	tmp->next = NULL;
	return (1);
}
