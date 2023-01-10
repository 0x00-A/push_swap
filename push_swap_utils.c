/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:33:11 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/08 18:09:48 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack)
{
	t_node	*tmp;
	t_node	*next;

	tmp = stack->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	stack->top = NULL;
	free(stack);
}

t_stacks	*ft_init(t_stacks *stacks)
{
	stacks->a = (t_stack *)malloc(sizeof(t_stack));
	stacks->b = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->a || !stacks->b)
		return (NULL);
	stacks->a->top = NULL;
	stacks->b->top = NULL;
	stacks->a->count = 0;
	stacks->b->count = 0;
	return (stacks);
}

void	ft_set_pos(t_stack *a)
{
	int		i;
	t_node	*head;

	i = 0;
	head = a->top;
	while (head)
	{
		head->pos = i;
		head = head->next;
		i++;
	}
}

void	ft_next_max(t_stack *a)
{
	t_node	*head;

	a->max = INT_MIN;
	head = a->top;
	while (head)
	{
		if (head->data >= a->max && head->final_rank == -1)
			a->max = head->data;
		head = head->next;
	}
}

void	ft_final_rank(t_stack *a)
{
	int		size;
	t_node	*tmp;

	size = a->count;
	while (size > 0)
	{
		tmp = a->top;
		ft_next_max(a);
		while (tmp)
		{
			if (tmp->data == a->max)
			{
				tmp->final_rank = size;
			}
			tmp = tmp->next;
		}
		size--;
	}
}
