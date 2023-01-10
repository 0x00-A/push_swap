/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:46:42 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/08 17:34:02 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_list_to_arr(t_stack *a, int *arr)
{
	t_node	*head;
	int		i;

	head = a->top;
	i = 0;
	while (head)
	{
		arr[i] = head->data;
		i++;
		head = head->next;
	}
}

static void	ft_lis_len(int *arr, int size, int *d)
{
	int	i;
	int	j;
	int	lis;

	i = 0;
	while (i < size)
		d[i++] = 1;
	i = 1;
	while (i < size)
	{
		lis = d[i];
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i])
			{
				if (lis + d[j] > d[i])
					d[i] = lis + d[j];
			}
			j++;
		}
		i++;
	}
}

static int	ft_lis_index(int *arr, int size)
{
	int	max;
	int	index;
	int	i;

	max = INT_MIN;
	index = -1;
	i = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	ft_set_lis_flag(t_stack *a, int *d)
{
	t_node	*head;
	int		index;

	head = a->top;
	index = 0;
	while (head)
	{
		if (d[index] == -1)
			head->lis_flag = -1;
		else
			head->lis_flag = 1;
		index++;
		head = head->next;
	}
}

void	ft_find_lis(t_stack *a)
{
	int	*arr;
	int	*d;
	int	lis_index;
	int	lis_max;

	arr = (int *)malloc(sizeof(int) * a->count);
	d = (int *)malloc(sizeof(int) * a->count);
	if (!arr || !d)
		return ;
	ft_list_to_arr(a, arr);
	ft_lis_len(arr, a->count, d);
	lis_index = ft_lis_index(d, a->count);
	lis_max = d[lis_index];
	while (lis_max > 0)
	{
		if (d[lis_index] == lis_max)
		{
			d[lis_index] = -1;
			lis_max--;
		}
		lis_index--;
	}
	ft_set_lis_flag(a, d);
	free(arr);
	free(d);
}
