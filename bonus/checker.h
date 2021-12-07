/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:07:34 by msainton          #+#    #+#             */
/*   Updated: 2021/12/07 15:35:54 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				element;
	struct s_stack	*next;
	struct s_stack	*prec;
}	t_stack;

typedef struct s_var
{
	t_stack	*first;
	t_stack	*last;
}	t_var;

typedef struct s_mynbr
{
	int	nbr;
	int	count;
}	t_mynbr;

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
void	pa(t_stack **stack_b, t_stack **stack_a);
void	ra(t_stack **stack);
void	rra(t_stack **stack);
void	sb(t_stack *stack);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack);
void	rrb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

t_stack	*get_last_element(t_stack *stack);
int		ft_stacksize(t_stack *stack);

int		db_nbr(int i, int ac, char **av);
int		max_value(char *str);
int		g_error(int argc, char **argv);
int		main(int argc, char **argv);

/*BONUS*/

int		stack_sort(t_stack *stack_a, t_stack *stack_b);
int		checker(t_stack **stack_a, t_stack **stack_b);
int		compare(char *s1, char *s2);
int		check_do(t_stack **stack_a, t_stack **stack_b, char *buff);

#endif
