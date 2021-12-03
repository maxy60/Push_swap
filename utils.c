/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:26:55 by maxime            #+#    #+#             */
/*   Updated: 2021/12/03 11:40:33 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_last_element(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int		min_value(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = stack->element;
	while (stack)
	{
		if (stack->element < i)
			i = stack->element;
		stack = stack->next;
	}
	return (i);
}

int		max_valuee(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = stack->element;
	while (stack)
	{
		if (stack->element > i)
			i = stack->element;
		stack = stack->next;
	}
	return (i);
}

int	ft_stacksize(t_stack *stack)
{
	int	a;

	a = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		a++;
	}
	return (a);
}