/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:21:57 by msainton          #+#    #+#             */
/*   Updated: 2021/11/02 17:38:04 by msainton         ###   ########.fr       */
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
	t_stack *a;
//	t_stack *b;
}	t_var;

t_stack	*ft_put_list(t_stack *lst, int element);
void	ft_put_list1(t_stack **lst, int element);
void	ft_put_list2(t_stack **lst);
void	ft_add_elem(t_stack **lst, int c);
void	swap(t_stack *stack_a);
void	push(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
t_stack	*ft_stacklast(t_stack *stack);
int	ft_stacksize(t_stack *stack);
int		main(int argc, char **argv);

#endif
