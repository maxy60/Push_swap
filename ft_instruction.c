/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:15:39 by msainton          #+#    #+#             */
/*   Updated: 2021/12/04 11:36:52 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	a;

	a = stack->element;
	stack->element = stack->next->element;
	stack->next->element = a;
}

void	push(t_stack **stack_a, t_stack **stack_b)
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

void	rotate(t_stack **stack)
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

void	reverse(t_stack	**stack)
{
	t_stack	*last;

	last = get_last_element(*stack);
	last->prec->next = NULL;
	(*stack)->prec = last;
	last->next = *stack;
	last->prec = NULL;
	*stack = last;
}
