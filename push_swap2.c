/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:53:02 by maxime            #+#    #+#             */
/*   Updated: 2021/12/03 11:53:21 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		stack = stack->next;
	}
	return (0);
}

int		pos_value_a(t_stack *stack, int nbr)
{
	int	i;
	int	size;
	t_stack	*last;

	last = get_last_element(stack);	
	i = 0;
	size = ft_stacksize(stack);
	if (size <= 1)
		return (i);
	if (nbr < min_value(stack))
		return(calc_b(stack, min_value(stack)));
	if (nbr < stack->element && nbr > last->element)
		return (0);
	stack = stack->next;
	i++;
	while(stack && !(nbr < stack->element &&  nbr > stack->prec->element) && nbr > min_value(stack))
	{
		i++;
		stack = stack->next;
	}
	return (i);
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
	if (nbr < stack_a->element && nbr > last->element)
		return (0);
	stack_a = stack_a->next;
	count++;
	while(stack_a && !(nbr < stack_a->element &&  nbr > stack_a->prec->element) && nbr > min_value(stack_a))
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
	mynbr.count = calc_b(stack_b, tmp->element) + calc_a(stack_a, tmp->element);
	while (tmp)
	{
		tmp_nbr = tmp->element;
		tmp_count = calc_b(stack_b, tmp->element) + calc_a(stack_a, tmp->element);
		if (tmp_count < mynbr.count)
		{
			mynbr.count = tmp_count;
			mynbr.nbr = tmp_nbr;
		}
		tmp = tmp->next;
	}
	return (mynbr);
}