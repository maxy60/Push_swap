/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:12:51 by msainton          #+#    #+#             */
/*   Updated: 2021/11/15 18:47:44 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_last_element(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	new_mediane(t_stack *stack)
{
	int 	i;
	int		j;
	int 	*stack_f;
	t_stack *tmp;

	i = 0;
	tmp = stack;
	stack_f = (int *)malloc(sizeof(int) * ft_stacksize(stack));
	while (tmp != NULL)
	{
		stack_f[i] = tmp->element;
		i++;
		tmp = tmp->next;
	}
	i = 0;
	while (i < ft_stacksize(stack))
	{
		printf("stack_f %d = %d\n", i, stack_f[i]);
		i++;
	}
	return (0);
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
	t_stack *last;
	int a;
	
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

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int b;

	while (ft_stacksize(*stack_a) != 1)
	{
		a = mediane(*stack_a);
		under_median(stack_a, stack_b);
	}
}