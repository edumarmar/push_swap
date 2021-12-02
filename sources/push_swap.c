/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:48 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/22 13:52:12 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	printlist(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			printf("%li\n", (long int) tmp->content);
		}
		else
		{
			printf("%li, ", (long int) tmp->content);
		}
		tmp = tmp->next;
	}
}

char	*join_arg(char **argv, int argc, t_list **stack_a)
{
	int		i;
	char	*str;
	char	*arg;

	i = 1;
	while (i <= (argc - 1))
	{
		if (ft_strlen(argv[i]) == 0 || is_empty(argv[i]))
			finish_ps(stack_a, 0);
		if (i == 1)
		{
			arg = ft_strjoin(argv[i], " ");
			i++;
			continue ;
		}
		else
		{
			str = ft_strjoin(arg, " ");
			free(arg);
		}
		arg = ft_strjoin(str, argv[i]);
		free(str);
		i++;
	}
	return (arg);
}

void	check_errors(int argc, char **argv, t_list **stack_a)
{
	char	*arg;

	arg = NULL;
	if (argc == 1)
		exit(1);
	else if (argc >= 2)
	{
		if (ft_strlen(argv[1]) == 0 || is_empty(argv[1]))
			finish_ps(stack_a, 0);
		arg = join_arg(argv, argc, stack_a);
		arg_to_stack(arg, stack_a);
		free(arg);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	check_errors(argc, argv, &stack_a);
	if (stack_isdup(stack_a))
		finish_ps(&stack_a, 0);
	if (!ft_lst_is_sorted(stack_a))
	{
		choose_sorting(&stack_a, &stack_b);
		deletelist(&stack_b);
		deletelist(&stack_a);
	}
	return (0);
}
