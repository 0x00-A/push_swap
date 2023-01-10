/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:31:59 by marvin            #+#    #+#             */
/*   Updated: 2023/01/08 02:31:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack *a)
{
	t_node	*head;
	int		min;

	min = INT_MAX;
	head = a->top;
	while (head)
	{
		if (head->data < min)
		{
			min = head->data;
		}
		head = head->next;
	}
	return (min);
}

int	ft_min_pos(t_stack *a)
{
	t_node	*head;
	int		min;
	int		pos;

	min = INT_MAX;
	head = a->top;
	while (head)
	{
		if (head->data < min)
		{
			min = head->data;
			pos = head->pos;
		}
		head = head->next;
	}
	return (pos);
}

void	ft_final_sort(t_stack *a)
{
	int	min;
	int	min_pos;

	a->med = a->count / 2;
	ft_set_pos(a);
	min = ft_min(a);
	min_pos = ft_min_pos(a);
	if (min_pos < a->med)
	{
		while (top(a) != min)
			ra(a, 1);
	}
	else if (min_pos >= a->med)
	{
		while (top(a) != min)
			rra(a, 1);
	}
}
