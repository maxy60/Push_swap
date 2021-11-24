/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:12:51 by msainton          #+#    #+#             */
/*   Updated: 2021/11/24 16:10:37 by maxime           ###   ########.fr       */
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
	int	count;
	int	size;

    count = 0;
	size = ft_stacksize(stack_b);

	if (size <= 1)
		return (count);
    while (stack_b && stack_b->element != nbr)
    {
        stack_b = stack_b->next;
        count++;
    }
    if (count > size / 2)
        return (size - count);
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

int		max_valuee(t_stack *stack)
{
	int	i;

	i = stack->element;
	while (stack)
	{
		if (stack->element > i)
			i = stack->element;
		stack = stack->next;
	}
	return (i);
}

int		pos_value_b(t_stack *stack, int nbr)
{
	int	i;
	int	size;

	i = 0;
	size = ft_stacksize(stack);
	if (size <= 1)
		return (i);
	while (stack)
	{
		if (stack->element == nbr)
			return (i);
		i++;
	}
	return (0);
}

int		pos_value_a(t_stack *stack, int nbr)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_stacksize(stack);
	if (size <= 1)
		return (i);
	if (nbr < min_value(stack))
		return(calc_b(stack, min_value(stack)));
	stack = stack->next;
	i++;
	while(stack && !(nbr > stack->element &&  nbr < stack->prec->element) && nbr > min_value(stack))
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int		calc_a(t_stack *stack_a, int nbr)
{
	int		count;
	t_stack	*last;
	int		size;

	size = ft_stacksize(stack_a);
	count = 0;
	last = get_last_element(stack_a);
	if (size <= 1)
		return(count);
	if (nbr < min_value(stack_a))
		return(calc_b(stack_a, min_value(stack_a)));
	stack_a = stack_a->next;
	count++;
	while(stack_a && !(nbr > stack_a->element &&  nbr < stack_a->prec->element) && nbr > min_value(stack_a))
	{
		count++;
		stack_a = stack_a->next;
	}
	if (count > size / 2)
		count = size - count;
	return (count);
}

t_mynbr	get_min_op(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp_nbr;
	int		tmp_count;
	t_stack	*tmp;
	t_mynbr	mynbr;
	
	tmp = stack_b;
	mynbr.nbr = tmp->element;
	mynbr.count = calc_b(stack_b, tmp->element) + calc_a(stack_a, tmp->element) + 1;
	while (tmp)
	{
		tmp_nbr = tmp->element;
		tmp_count = calc_b(stack_b, tmp->element) + calc_a(stack_a, tmp->element) + 1;
		if (tmp_count < mynbr.count)
		{
			mynbr.count = tmp_count;
			mynbr.nbr = tmp_nbr;
		}
		tmp = tmp->next;
	}
	return (mynbr);
}

void	do_op(t_stack **stack_a, t_stack **stack_b)
{
	t_mynbr mynbr;
	
	mynbr = get_min_op((*stack_a), (*stack_b));
	int	tmp_a;
	int	tmp_b;
	tmp_b = calc_b((*stack_b), mynbr.nbr);
	while (tmp_b > 0)
	{
		if (ft_stacksize((*stack_b)) > 2)
		{
			if (pos_value_b((*stack_b), mynbr.nbr) > ft_stacksize((*stack_b)) / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}	
		else
			sb((*stack_b));
		tmp_b--;
	}
	tmp_a = calc_a((*stack_a), mynbr.nbr);
	while (tmp_a > 0)
	{
			if (pos_value_a((*stack_a), mynbr.nbr) > ft_stacksize((*stack_a)) / 2)
				rra(stack_a);
			else
				ra(stack_a);
		tmp_a--;
	}
	printf(" STACKb = %d mynbr = %d count = %d\n", (*stack_b)->element, mynbr.nbr, mynbr.count);
	pb(stack_b, stack_a);	
}

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	t_mynbr	mynbr;

	while (ft_stacksize(*stack_a) > 1)
	{
		a = mediane(*stack_a);
		under_median(stack_a, stack_b);
	}
	pb(stack_b, stack_a);

	while ((*stack_b))
		do_op(stack_a, stack_b);

}