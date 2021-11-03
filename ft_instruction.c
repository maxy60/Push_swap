/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:49:32 by msainton          #+#    #+#             */
/*   Updated: 2021/11/03 15:47:59 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
		return (stack);
}

void	swap(t_stack *stack_a)
{
	int a;

	a = stack_a->element;
	stack_a->element = stack_a->next->element;
	stack_a->next->element = a;
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *tmp_b;

	tmp = *stack_a;
	tmp_b = *stack_b;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (tmp_b != NULL)
	    tmp->next = tmp_b->next;
	*stack_b = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		tmp_1;

	tmp = *stack;
	tmp_1 = tmp->element;
	while (tmp->next != NULL)
	{
		tmp->element = tmp->next->element;
		tmp = tmp->next;
	}
	tmp->element = tmp_1;
	tmp->next = NULL;
}

void	inverse(t_stack	**stack)
{
	t_stack *tmp;
	int		tmp_1;

	tmp = *stack;
	tmp_1 = tmp->element;
	while (tmp->prec != NULL)
	{
		tmp->element = tmp->prec->element;
		tmp = tmp->prec;
	}
	tmp->element = tmp_1;
	tmp->prec = NULL;
}
