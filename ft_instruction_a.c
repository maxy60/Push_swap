/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:49:32 by msainton          #+#    #+#             */
/*   Updated: 2021/11/16 15:13:30 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
		return (stack);
}

void	sa(t_stack *stack)
{
	int a;

	a = stack->element;
	stack->element = stack->next->element;
	stack->next->element = a;
	ft_putstr("sa\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
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
	ft_putstr("pa\n");
}

void	ra(t_stack **stack)
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
	ft_putstr("ra\n");	
}

void	rra(t_stack	**stack)
{
	t_stack *last;

	last = get_last_element(*stack);
	last->prec->next = NULL;
	(*stack)->prec = last;
	last->next = *stack;
	last->prec = NULL;
	*stack = last;
	ft_putstr("rra\n");
}
