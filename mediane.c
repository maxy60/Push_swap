/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:47:01 by maxime            #+#    #+#             */
/*   Updated: 2021/12/03 11:47:56 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(t_stack *stack, int *stack_f)
{
	int		i;
	int		j;
	int		k;
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

static int	*ft_array(t_stack *stack)
{
	int 	i;
	int		j;
	int		k;
	int 	*stack_f;
	t_stack *tmp;

	i = 0;
	tmp = stack;
	stack_f = (int *)malloc(sizeof(int) * ft_stacksize(stack));
	if (!stack_f)
		return (NULL);
	while (tmp != NULL)
	{
		stack_f[i] = tmp->element;
		i++;
		tmp = tmp->next;
	}
	sort_array(stack, stack_f);
	return (stack_f);
}

static int	mediane(t_stack *stack)
{
	int	a;
	int	b;
	int	*array;

	b = 0;
	array = ft_array(stack);
	a = ft_stacksize(stack) / 2;
	b = array[a];
	free(array);
	return (b);
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
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}