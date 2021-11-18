/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:12:51 by msainton          #+#    #+#             */
/*   Updated: 2021/11/18 17:33:37 by msainton         ###   ########.fr       */
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
	if (!stack_f)
		return (NULL);
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
	return (stack_f);
}

int	mediane(t_stack *stack)
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
			pa(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

int		calc_b(t_stack *stack_b, int nbr)
{
	int		count;
	
	count = 0;
	while (stack_b != NULL)
	{
		nbr = stack_b->element;
		count++;
		if (ft_stacksize(stack_b) / 2 + 1 > count)
			count--;
		stack_b = stack_b->next;
	}
	return (count);
}

int		min_value(t_stack *stack)
{
	int	i;

	i = stack->element;
	while (stack)
	{
		if (stack->element < i)
			i = stack->element;
		stack = stack->next;
	}
	return (i);
}
int		calc_a(t_stack *stack_a, int nbr)
{
	int		count;
	t_stack	*last;

	count = 0;
	last = get_last_element(stack_a);
	if (nbr > stack_a->element && nbr < last->element && nbr > min_value(stack_a))
		return (count);
	stack_a = stack_a->next;
	count++;
	while(nbr > stack_a->element &&  nbr < stack_a->prec->element && nbr > min_value(stack_a))
	{
		count++;
		stack_a = stack_a->next;
	}
	if (count > ft_stacksize(stack_a) / 2)
		count = ft_stacksize(stack_a) - count;
	return (count);
}

t_mynbr	*get_min_op(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp_nbr;
	int		tmp_count;
	t_stack	*tmp;
	t_mynbr	*mynbr;
	
	mynbr->nbr = stack_b->element;
	mynbr->count = calc_b(stack_b, stack_b->element) + calc_a(stack_a, stack_b->element);
	while (stack_b)
	{
		tmp_nbr = stack_b->element;
		tmp_count = calc_b(stack_b, stack_b->element) + calc_a(stack_a, stack_b->element);
		if (tmp_count < mynbr->count)
		{
			mynbr->count = tmp_count;
			mynbr->nbr = tmp_nbr;
		}
		stack_b = stack_b->next;
	}
	return (mynbr);
}
void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	t_mynbr	mynbr;

	while (ft_stacksize((*stack_a)) > 1)
	{
		a = mediane(*stack_a);
		under_median(stack_a, stack_b);
	}
	pb(stack_b, stack_a);
	while (ft_stacksize((*stack_b)) >= 1)
	{
		mynbr = get_min_op((*stack_a), (*stack_b));
		if (mynbr.count == 1)
			pb(stack_b, stack_a);
		printf("nbr = %d\ncount = %d\n", mynbr.nbr, mynbr.count);
	}
}