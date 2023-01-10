/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:31:33 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/10 15:23:47 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//includes
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct node{
	int				data;
	struct node		*next;
	int				pos;
	int				target_pos;
	int				final_rank;
	int				cost_stack_a;
	int				cost_stack_b;
	int				lis_flag;
}							t_node;

typedef struct s_stack{
	t_node			*top;
	int				count;
	int				max;
	int				med;
	int				max_index;
	int				med_index;
}						t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct s_cost{
	int	cost_a;
	int	cost_b;
}				t_cost;

//operations
void		push(t_stack *stack, int data);
void		pop(t_stack *stack);
int			is_empty(t_stack *stack);
int			top(t_stack *stack);
void		sa(t_stack *a, int i);
void		sb(t_stack *b, int i);
void		ss(t_stacks *stacks, int i);
void		pa(t_stacks *stacks, int i);
void		pb(t_stacks *stacks, int i);
void		ra(t_stack *a, int i);
void		rb(t_stack *b, int i);
void		rr(t_stacks *stacks, int i);
void		rra(t_stack *a, int i);
void		rrb(t_stack *b, int i);
void		rrr(t_stacks *stacks, int i);

//
void		ft_free(t_stack *stack);
t_stacks	*ft_init(t_stacks *stacks);
int			check_arg(char *arg);
int			check_dup(t_stack *a);
int			stack_is_sorted(t_stack *a);
int			ft_create_stack(t_stacks *stacks, int ac, char **av);

void		ft_sortsmallstack(t_stacks *stacks);
void		ft_sortmediumstack(t_stacks *stacks);
void		ft_push_swap(t_stacks *stacks);

void		ft_set_pos(t_stack *a);
void		ft_next_max(t_stack *a);
void		ft_final_rank(t_stack *a);
void		ft_find_lis(t_stack *a);
void		ft_best_move(t_stacks *stacks);
void		ft_final_sort(t_stack *a);

//bonus
int			ft_check_error(char *action);
void		ft_apply_actions(t_stacks *stacks, char *action);

#endif
