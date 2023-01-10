/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 03:38:34 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/08 17:20:39 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stacks *stacks, int i)
{
	ra(stacks->a, 0);
	rb(stacks->b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}

void	rra(t_stack *a, int i)
{
	t_node	*tmp;
	t_node	*before_last;

	if (!a || is_empty(a) || a->top->next == NULL)
		return ;
	before_last = a->top;
	tmp = a->top;
	while (before_last->next->next)
		before_last = before_last->next;
	a->top = before_last->next;
	before_last->next = NULL;
	a->top->next = tmp;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int i)
{
	t_node	*tmp;
	t_node	*before_last;

	if (!b || is_empty(b) || b->top->next == NULL)
		return ;
	before_last = b->top;
	tmp = b->top;
	while (before_last->next->next)
		before_last = before_last->next;
	b->top = before_last->next;
	before_last->next = NULL;
	b->top->next = tmp;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks, int i)
{
	rra(stacks->a, 0);
	rrb(stacks->b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}

int	top(t_stack *stack)
{
	return (stack->top->data);
}
