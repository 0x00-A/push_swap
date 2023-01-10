/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 05:56:56 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/10 15:24:41 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(char *action)
{
	if (!ft_strcmp(action, "sa\n"))
		return (1);
	if (!ft_strcmp(action, "sb\n"))
		return (1);
	if (!ft_strcmp(action, "ss\n"))
		return (1);
	if (!ft_strcmp(action, "pa\n"))
		return (1);
	if (!ft_strcmp(action, "pb\n"))
		return (1);
	if (!ft_strcmp(action, "ra\n"))
		return (1);
	if (!ft_strcmp(action, "rb\n"))
		return (1);
	if (!ft_strcmp(action, "rr\n"))
		return (1);
	if (!ft_strcmp(action, "rra\n"))
		return (1);
	if (!ft_strcmp(action, "rrb\n"))
		return (1);
	if (!ft_strcmp(action, "rrr\n"))
		return (1);
	return (0);
}

void	ft_apply_actions(t_stacks *stacks, char *action)
{
	if (!ft_strcmp(action, "sa\n"))
		return (sa(stacks->a, 2));
	else if (!ft_strcmp(action, "sb\n"))
		return (sb(stacks->b, 2));
	else if (!ft_strcmp(action, "ss\n"))
		return (ss(stacks, 2));
	else if (!ft_strcmp(action, "pa\n"))
		return (pa(stacks, 2));
	else if (!ft_strcmp(action, "pb\n"))
		return (pb(stacks, 2));
	else if (!ft_strcmp(action, "ra\n"))
		return (ra(stacks->a, 2));
	else if (!ft_strcmp(action, "rb\n"))
		return (rb(stacks->b, 2));
	else if (!ft_strcmp(action, "rr\n"))
		return (rr(stacks, 2));
	else if (!ft_strcmp(action, "rra\n"))
		return (rra(stacks->a, 2));
	else if (!ft_strcmp(action, "rrb\n"))
		return (rrb(stacks->b, 2));
	else if (!ft_strcmp(action, "rrr\n"))
		return (rrr(stacks, 2));
}
