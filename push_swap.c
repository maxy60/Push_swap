/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:12:51 by msainton          #+#    #+#             */
/*   Updated: 2021/11/10 17:37:29 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_last_element(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
int	mediane(t_stack *stack)
{
	long long int a;
	long long int b;
	
	a = 0;
	b = 0;
	while (stack != NULL)
	{
		a = a + stack->element;
		b++;
		stack = stack->next;
	}
	return (a / b);
}
void	under_median(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *last;
	int a;
	
	tmp = *stack_a;
	last = get_last_element(*stack_a);
	a = mediane(*stack_a);
	while ((*stack_a) != last)
	{
		if ((*stack_a)->element < a)
			push(stack_a, stack_b);
		else
			rotate(stack_a);
	}
	if (last->element <= a)
		push(stack_a, stack_b);
}

void algo(t_stack **stack_a, t_stack **stack_b)
{
	int	a;

	while (ft_stacksize(*stack_a) != 1)
	{
		a = mediane(*stack_a);
		printf("mediane = %d", a);
		under_median(stack_a, stack_b);
	}
}