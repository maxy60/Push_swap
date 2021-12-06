/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_a_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:49:32 by msainton          #+#    #+#             */
/*   Updated: 2021/12/06 21:26:14 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	sa(t_stack *stack)
{
	int	a;

	a = stack->element;
	stack->element = stack->next->element;
	stack->next->element = a;
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*new_head;

	if (*stack_b == NULL)
		return ;
	new_head = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prec = NULL;
	new_head->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prec = new_head;
	*stack_a = new_head;
}

void	ra(t_stack **stack)
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

void	rra(t_stack	**stack)
{
	t_stack	*last;

	last = get_last_element(*stack);
	last->prec->next = NULL;
	(*stack)->prec = last;
	last->next = *stack;
	last->prec = NULL;
	*stack = last;
}
