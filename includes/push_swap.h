/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:03:32 by edmartin          #+#    #+#             */
/*   Updated: 2021/11/22 12:34:46 by edmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef MAX_SIZE
#  define MAX_SIZE 20
# endif

int			is_empty(char *argv);
void		arg_to_stack(const char *arg, t_list **stack_a);
int			ft_strisnum(char *str);
int			ft_lst_is_sorted(t_list *stack);
int			ft_lst_is_backsorted(t_list *stack);
int			stack_isdup(t_list *stack);
void		finish_ps(t_list **stack_a, t_list **stack_b);

void		deletelist(t_list **lst);

int			swap(t_list **stack, int len, char *print);
int			push(t_list **stack_1, t_list **stack_2, char *print);
int			rotate(t_list **stack, char *print);
int			rev_rotate(t_list **stack, char *print);
void		action_n(t_list **stack, char *action, int n, char *print);

int			ft_stack_max_value(t_list *stack);
int			ft_stack_min_value(t_list *stack);
void		push_max_min(t_list **stack_src, t_list **stack_dest, \
			char *min_or_max, char *print);

void		choose_sorting(t_list **stack_a, t_list **stack_b);
void		sort_three(t_list **stack);
void		sort_five(t_list **stack_a, t_list **stack_b);

void		findspot_b(t_list **stack_a, t_list **stack_b);
void		max_to_top(t_list **stack);
void		sort_large(t_list **stack_a, t_list **stack_b, \
			int div, int mv_last);
float		*divide(t_list **stack_a, int division);

int			search_first(t_list *lst, int threshold);
int			search_last(t_list *lst, int threshold);
int			search_num(t_list *lst, int num);

#endif
