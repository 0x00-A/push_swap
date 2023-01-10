/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:33:44 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/10 15:13:27 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	if (stacks->a->count <= 3)
		ft_sortsmallstack(stacks);
	else if (stacks->a->count <= 5)
		ft_sortmediumstack(stacks);
	else
		ft_push_swap(stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	if (!ft_init(stacks))
		exit(1);
	if (ac > 1)
	{
		if (ft_create_stack(stacks, ac, av))
		{
			if (check_dup(stacks->a))
			{
				if (!stack_is_sorted(stacks->a))
					ft_sort(stacks);
			}
		}
	}
	ft_free(stacks->a);
	ft_free(stacks->b);
	free(stacks);
	return (0);
}
