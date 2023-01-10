/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:33:11 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/08 17:35:01 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_non_lis(t_stacks *stacks)
{
	t_stack	*tmp;
	int		i;
	int		size;

	i = -1;
	size = stacks->a->count;
	stacks->a->med = stacks->a->count / 2;
	tmp = stacks->a;
	while (++i < size)
	{
		if (tmp->top->final_rank <= stacks->a->med && tmp->top->lis_flag != -1)
			pb(stacks, 1);
		else
			ra(stacks->a, 1);
	}
	i = -1;
	size = stacks->a->count;
	while (++i < size)
	{
		if (tmp->top->lis_flag != -1)
			pb(stacks, 1);
		else
			ra(stacks->a, 1);
	}
}

void	ft_get_target_pos(t_stack *a, int stack_b_rank, int closest_rank,
														int *target_pos)
{
	t_node	*curr;

	curr = a->top;
	while (curr)
	{
		if (stack_b_rank < curr->final_rank && curr->final_rank < closest_rank)
		{
			closest_rank = curr->final_rank;
			*target_pos = curr->pos;
		}
		curr = curr->next;
	}
	if (closest_rank != INT_MAX)
		return ;
	curr = a->top;
	while (curr)
	{
		if (curr->final_rank < closest_rank)
		{
			closest_rank = curr->final_rank;
			*target_pos = curr->pos;
		}
		curr = curr->next;
	}
	return ;
}

void	ft_set_target_pos(t_stacks *stacks)
{
	t_node	*tmp_b;
	int		target_pos;

	ft_set_pos(stacks->a);
	ft_set_pos(stacks->b);
	tmp_b = stacks->b->top;
	while (tmp_b)
	{
		ft_get_target_pos(stacks->a, tmp_b->final_rank, INT_MAX, &target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

void	ft_set_cost(t_stacks *stacks)
{
	t_node	*head;

	stacks->b->med = stacks->b->count / 2;
	stacks->a->med = stacks->a->count / 2;
	head = stacks->b->top;
	while (head)
	{
		if (head->pos < stacks->b->med)
			head->cost_stack_b = head->pos;
		else
			head->cost_stack_b = -(stacks->b->count - head->pos);
		if (head->target_pos < stacks->a->med)
			head->cost_stack_a = head->target_pos;
		else
			head->cost_stack_a = -(stacks->a->count - head->target_pos);
		head = head->next;
	}
}

void	ft_push_swap(t_stacks *stacks)
{
	ft_set_pos(stacks->a);
	ft_final_rank(stacks->a);
	ft_find_lis(stacks->a);
	ft_push_non_lis(stacks);
	while (stacks->b->count)
	{
		ft_set_target_pos(stacks);
		ft_set_cost(stacks);
		ft_best_move(stacks);
	}
	if (!stack_is_sorted(stacks->a))
		ft_final_sort(stacks->a);
}
