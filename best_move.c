/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:59:30 by marvin            #+#    #+#             */
/*   Updated: 2023/01/08 02:59:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	ft_rotate_a(t_stack *a, int stack_cost)
{
	while (stack_cost)
	{
		if (stack_cost < 0)
		{
			rra(a, 1);
			stack_cost += 1;
		}
		else
		{
			ra(a, 1);
			stack_cost -= 1;
		}
	}
	return (stack_cost);
}

int	ft_rotate_b(t_stack *b, int stack_cost)
{
	while (stack_cost)
	{
		if (stack_cost < 0)
		{
			rrb(b, 1);
			stack_cost += 1;
		}
		else
		{
			rb(b, 1);
			stack_cost -= 1;
		}
	}
	return (stack_cost);
}

void	ft_exc_move(t_stacks *stacks, t_cost costs)
{
	if (costs.cost_a > 0 && costs.cost_b > 0)
	{
		while (costs.cost_a > 0 && costs.cost_b > 0)
		{
			rr(stacks, 1);
			costs.cost_a -= 1;
			costs.cost_b -= 1;
		}
	}
	else if (costs.cost_a < 0 && costs.cost_b < 0)
	{
		while (costs.cost_a < 0 && costs.cost_b < 0)
		{
			rrr(stacks, 1);
			costs.cost_a += 1;
			costs.cost_b += 1;
		}
	}	
	costs.cost_a = ft_rotate_a(stacks->a, costs.cost_a);
	costs.cost_b = ft_rotate_b(stacks->b, costs.cost_b);
	pa(stacks, 1);
}

void	ft_best_move(t_stacks *stacks)
{
	t_cost	costs;
	t_node	*tmp;
	int		cost;
	int		least;

	costs.cost_a = 0 ;
	costs.cost_b = 0 ;
	least = INT_MAX;
	tmp = stacks->b->top;
	while (tmp)
	{
		cost = ft_abs(tmp->cost_stack_a) + ft_abs(tmp->cost_stack_b);
		if (cost < least)
		{
			least = cost;
			costs.cost_a = tmp->cost_stack_a;
			costs.cost_b = tmp->cost_stack_b;
		}
		tmp = tmp->next;
	}
	ft_exc_move(stacks, costs);
}
