/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:43 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/11 18:10:45 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_empty(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] > 47 && str[i] < 58) && str[i] != 32 && str[i] != 45)
			return (0);
		i++;
	}
	return (1);
}

void	finish_ps(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		deletelist(stack_a);
	if (stack_b)
		deletelist(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	arg_to_stack(const char *arg, t_list **stack_a)
{
	int			i;
	long int	data;
	t_list		*new_node;

	i = 0;
	if (!ft_strisnum((char *)arg))
		finish_ps(stack_a, 0);
	while (arg[i])
	{
		while (arg[i] == ' ' || arg[i] == '\t' || arg[i] == '\f' || \
		arg[i] == '\r' || arg[i] == '\n' || arg[i] == '\v')
			i++;
		if (!arg[i])
			break ;
		data = ft_atoi(&arg[i]);
		if (data < -2147483648 || data > 2147483647)
			finish_ps(stack_a, 0);
		while ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == 45)
			i++;
		new_node = ft_lstnew((int *)data);
		if (!new_node)
			finish_ps(stack_a, 0);
		ft_lstadd_back(stack_a, new_node);
	}
}
