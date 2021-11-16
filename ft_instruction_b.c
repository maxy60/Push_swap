/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:53:24 by msainton          #+#    #+#             */
/*   Updated: 2021/11/16 15:43:57 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
{
	int a;

	a = stack->element;
	stack->element = stack->next->element;
	stack->next->element = a;
    ft_putstr("sb\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	*stack_a = tmp_a->next;
	if (tmp_b != NULL)
	    tmp_a->next = *stack_b;
	else
		tmp_a->next = NULL;
	*stack_b = tmp_a;
    ft_putstr("pb\n");
}

void	rb(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	first = *stack;
	*stack = (*stack)->next;
	last = get_last_element(*stack);
	last->next = first;
	first->next->prec = NULL;
	first->prec = last;
	first->next = NULL;
    ft_putstr("rb\n");	
}

void	rrb(t_stack	**stack)
{
	t_stack *last;

	last = get_last_element(*stack);
	last->prec->next = NULL;
	(*stack)->prec = last;
	last->next = *stack;
	last->prec = NULL;
	*stack = last;
    ft_putstr("rrb\n");
}
