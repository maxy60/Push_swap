/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:21:57 by msainton          #+#    #+#             */
/*   Updated: 2021/11/18 22:46:25 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_stack
{
	int	element;
	struct s_stack *next;
	struct s_stack *prec;
}	t_stack;

typedef struct s_var
{
	t_stack *first;
	t_stack *last;
}	t_var;

typedef struct s_mynbr
{
	int	nbr;
	int	count;
}	t_mynbr;

t_stack *get_last_element(t_stack *stack);
void	init(t_var *l);
void	init1(t_mynbr *nbr);
void	pushback(t_var *l, int element);
void	pushfront(t_var *l, int element);
void	ft_put_list1(t_stack **lst, int element);
void	swap(t_stack *stack);
void	push(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);
void	sa(t_stack *stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	sb(t_stack *stack);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack);
void	rrb(t_stack **stack);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
int		*ft_array(t_stack *stack);
int		mediane(t_stack *stack);
void	under_median(t_stack **stack_a, t_stack **stack_b);
int		calc_b(t_stack *b, int nbr);
int		calc_a(t_stack *a, int nbr);
t_mynbr	get_min_op(t_stack *stack_a, t_stack *stack_b);
void	algo(t_stack **stack_a, t_stack **stack_b);
void	algo2(t_stack *stack_a);
void	algo3(t_stack **stack_a);
void    algo4(t_stack **stack_a, t_stack **stack_b);
void	algo5(t_stack **stack_a, t_stack **stack_b);


int		main(int argc, char **argv);

#endif
