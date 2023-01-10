/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 01:49:28 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/08 17:20:46 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stacks *stacks, int i)
{
	sa(stacks->a, 0);
	sb(stacks->b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa(t_stacks *stacks, int i)
{
	t_node	*tmp;
	t_node	*head;

	if (is_empty(stacks->b))
		return ;
	stacks->a->count++;
	stacks->b->count--;
	tmp = stacks->b->top->next;
	if (is_empty(stacks->a))
	{
		stacks->a->top = stacks->b->top;
		stacks->b->top->next = NULL;
	}
	else
	{
		head = stacks->a->top;
		stacks->a->top = stacks->b->top;
		stacks->b->top->next = head;
	}
	stacks->b->top = tmp;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, int i)
{
	t_node	*tmp;
	t_node	*head;

	if (is_empty(stacks->a))
		return ;
	stacks->a->count--;
	stacks->b->count++;
	tmp = stacks->a->top->next;
	if (is_empty(stacks->b))
	{
		stacks->b->top = stacks->a->top;
		stacks->a->top->next = NULL;
	}
	else
	{
		head = stacks->b->top;
		stacks->b->top = stacks->a->top;
		stacks->a->top->next = head;
	}
	stacks->a->top = tmp;
	if (i == 1)
		write(1, "pb\n", 3);
}

void	ra(t_stack *a, int i)
{
	t_node	*tmp;
	t_node	*last;

	if (!a || is_empty(a) || a->top->next == NULL)
		return ;
	tmp = a->top;
	last = a->top;
	a->top = a->top->next;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int i)
{
	t_node	*tmp;
	t_node	*last;

	if (!b || is_empty(b) || b->top->next == NULL)
		return ;
	tmp = b->top;
	last = b->top;
	b->top = b->top->next;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}
