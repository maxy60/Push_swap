/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:12:51 by msainton          #+#    #+#             */
/*   Updated: 2021/11/16 19:00:49 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_last_element(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	*ft_array(t_stack *stack)
{
	int 	i;
	int		j;
	int		k;
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
		j = i + 1;
		while (j < ft_stacksize(stack))
		{
			if (stack_f[i] > stack_f[j])
			{
				k = stack_f[i];
				stack_f[i] = stack_f[j];
				stack_f[j] = k;
			}
			j++;
		}
		i++;
	}
}

int	mediane(t_stack *stack)
{
	int	a;
	int	*array;

	array = ft_array(stack);
	a = ft_stacksize(stack) / 2;
	printf("a = %d\n", a);
	return (array[a]);
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