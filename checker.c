/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 03:54:04 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/10 16:02:51 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_read_arg(t_stacks *stacks, int ac, char **av)
{
	if (ac == 1)
	{
		return (0);
	}
	else
	{
		if (!ft_create_stack(stacks, ac, av))
			return (0);
	}
	return (1);
}

int	ft_read_action(t_stacks *stacks)
{
	char	*action;

	action = get_next_line(0);
	while (action)
	{
		if (!ft_check_error(action))
		{
			free(action);
			return (ft_error());
		}
		ft_apply_actions(stacks, action);
		free(action);
		action = NULL;
		action = get_next_line(0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	if (!ft_init(stacks))
		exit(1);
	if (ft_read_arg(stacks, ac, av))
	{
		if (check_dup(stacks->a))
		{
			if (ft_read_action(stacks))
			{
				if (stack_is_sorted(stacks->a) && stacks->b->count == 0)
					write(1, "OK\n", 3);
				else
					write(1, "KO\n", 3);
			}
		}
	}
	ft_free(stacks->a);
	ft_free(stacks->b);
	free(stacks);
	return (0);
}
