/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:17:19 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/08 17:09:51 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_max(t_stack *a)
{
	t_node	*head;

	a->max = INT_MIN;
	head = a->top;
	while (head)
	{
		if (head->data > a->max)
			a->max = head->data;
		head = head->next;
	}
}

void	ft_max_index(t_stack *a)
{
	t_node	*head;

	a->max_index = -1;
	head = a->top;
	while (head)
	{
		if (head->data == a->max)
			return ;
		head = head->next;
		a->max_index++;
	}
}

void	ft_sortsmallstack(t_stacks *stacks)
{
	ft_max(stacks->a);
	if (stacks->a->count == 2)
	{
		if (stacks->a->top->data > stacks->a->top->next->data)
			sa(stacks->a, 1);
	}
	else
	{
		if (stacks->a->top->data == stacks->a->max)
			ra(stacks->a, 1);
		if (stacks->a->top->next->data == stacks->a->max)
			rra(stacks->a, 1);
		if (stacks->a->top->data > stacks->a->top->next->data)
			sa(stacks->a, 1);
	}
}

void	ft_move_max(t_stacks *stacks)
{
	ft_max(stacks->a);
	stacks->a->med = stacks->a->count / 2;
	stacks->a->max = stacks->a->max;
	ft_max_index(stacks->a);
	if (stacks->a->max_index < stacks->a->med)
	{
		while (top(stacks->a) != stacks->a->max)
			ra(stacks->a, 1);
	}
	else if (stacks->a->max_index >= stacks->a->med)
	{
		while (top(stacks->a) != stacks->a->max)
			rra(stacks->a, 1);
	}
}

void	ft_sortmediumstack(t_stacks *stacks)
{
	int	i;

	i = stacks->a->count - 3;
	while (i > 0)
	{
		ft_move_max(stacks);
		pb(stacks, 1);
		i--;
	}
	ft_sortsmallstack(stacks);
	if (stacks->b->count == 1)
	{
		pa(stacks, 1);
		ra(stacks->a, 1);
	}
	else
	{
		pa(stacks, 1);
		ra(stacks->a, 1);
		pa(stacks, 1);
		ra(stacks->a, 1);
	}
}
