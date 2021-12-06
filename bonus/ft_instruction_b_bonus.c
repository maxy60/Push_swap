/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_b_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:53:24 by msainton          #+#    #+#             */
/*   Updated: 2021/12/06 21:26:42 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_stack *stack)
{
	int	a;

	a = stack->element;
	stack->element = stack->next->element;
	stack->next->element = a;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_head;

	if (*stack_a == NULL)
		return ;
	new_head = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prec = NULL;
	new_head->next = (*stack_b);
	if (*stack_b)
		(*stack_b)->prec = new_head;
	*stack_b = new_head;
}

void	rb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = get_last_element(*stack);
	last->next = first;
	first->next->prec = NULL;
	first->prec = last;
	first->next = NULL;
}

void	rrb(t_stack	**stack)
{
	t_stack	*last;

	last = get_last_element(*stack);
	last->prec->next = NULL;
	(*stack)->prec = last;
	last->next = *stack;
	last->prec = NULL;
	*stack = last;
}
