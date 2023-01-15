/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:46:02 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/13 16:22:39 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *a)
{
	t_node	*tmp;
	t_node	*head;

	if (a->top == NULL)
		return (0);
	head = a->top;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->data > tmp->data)
				return (0);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
}

int	check_dup(t_stack *a)
{
	t_node	*tmp;
	t_node	*head;

	if (is_empty(a))
		return (0);
	head = a->top;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->data == tmp->data)
			{
				return (ft_error());
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
}

int	check_arg(char *arg)
{
	long int	r;
	int			sign;

	r = 0;
	sign = 1;
	if (ft_strlen(arg) == 1 && (arg[0] == '-' || arg[0] == '+'))
		return (1);
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (1);
		r = r * 10 + *arg - '0';
		arg++;
	}
	if (!(r * sign <= INT_MAX && r * sign >= INT_MIN))
		return (1);
	return (0);
}

int	ft_create_stack_helper(t_stacks *stacks, char **p, int count)
{
	while (count--)
	{
		if (check_arg(p[count]))
		{
			ft_free_tab(p, ++count);
			return (ft_error());
		}
		push(stacks->a, atoi(p[count]));
		free(p[count]);
		stacks->a->count++;
	}
	return (1);
}

int	ft_create_stack(t_stacks *stacks, int ac, char **av)
{
	char	**p;
	int		count;
	int		tmp;

	tmp = ac;
	while (--ac > 0)
	{
		p = ft_split(av[ac], ' ');
		if (!p)
			return (0);
		count = ft_count_word(av[ac], ' ');
		if (!count)
		{
			free(p);
			return (ft_error());
		}
		if (!ft_create_stack_helper(stacks, p, count))
			return (0);
		free(p);
	}
	return (1);
}
