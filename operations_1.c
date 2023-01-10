/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 01:07:30 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/05 13:11:13 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	push(t_stack *stack, int data)
{
	t_node	*node;
	t_node	*tmp;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->data = data;
	node->next = NULL;
	node->final_rank = -1;
	if (is_empty(stack))
		stack->top = node;
	else
	{
		tmp = stack->top;
		stack->top = node;
		stack->top->next = tmp;
	}
}

void	pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
}

void	sa(t_stack *a, int i)
{
	t_node	*tmp;

	if (a->top == NULL || a->top->next == NULL)
		return ;
	tmp = a->top->next;
	a->top->next = a->top->next->next;
	tmp->next = a->top;
	a->top = tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int i)
{
	t_node	*tmp;

	if (b->top == NULL || b->top->next == NULL)
		return ;
	tmp = b->top->next;
	b->top->next = b->top->next->next;
	tmp->next = b->top;
	b->top = tmp;
	if (i == 1)
		write(1, "sb\n", 3);
}
