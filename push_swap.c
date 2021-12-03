/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:12:51 by msainton          #+#    #+#             */
/*   Updated: 2021/11/24 17:16:112 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	db_op(t_stack **stack_a, t_stack **stack_b)
{
	t_mynbr mynbr;
	int		pos_a; 
	int		pos_b;
	int		tmp_a;
	int		tmp_b;
	int		tmp_count;

	mynbr = get_min_op((*stack_a), (*stack_b));
	pos_a = pos_value_a((*stack_a), mynbr.nbr);
	pos_b = pos_value_b((*stack_b), mynbr.nbr);
	tmp_count = mynbr.count;

	if (pos_a > (ft_stacksize(*stack_a) / 2) && pos_b > (ft_stacksize(*stack_b) / 2))
	{
		while (pos_value_a((*stack_a), mynbr.nbr) != 0 && pos_value_b((*stack_b), mynbr.nbr) != 0)
			rrr(stack_a, stack_b);
	}
	else if (pos_a <= (ft_stacksize(*stack_a) / 2) && pos_b <= (ft_stacksize(*stack_b) / 2))
	{
		while (pos_value_a((*stack_a), mynbr.nbr) != 0 && pos_value_b((*stack_b), mynbr.nbr) != 0)
			rr(stack_a, stack_b);		
	}
}

void	do_opb(t_stack **stack_a, t_stack **stack_b)
{
	t_mynbr mynbr;
	int		tmp_b;
	int		pos_b;

	mynbr = get_min_op((*stack_a), (*stack_b));
	pos_b = pos_value_b((*stack_b), mynbr.nbr);
	tmp_b = calc_b((*stack_b), mynbr.nbr);
	while (tmp_b > 0)
	{
		if (ft_stacksize((*stack_b)) > 2)
		{
			if (pos_b > ft_stacksize((*stack_b)) / 2)
				rrb(stack_b);
			else
				rb(stack_b);
		}	
		else if (ft_stacksize((*stack_b)) == 2)
			sb((*stack_b));
		tmp_b--;
	}
}


void	check_min(t_stack **stack_a, int nbr)
{
	if (pos_value_b(*stack_a, min_value(*stack_a)) >= ft_stacksize(*stack_a)/2)
	{
		while ((*stack_a)->element != min_value(*stack_a))
			rra(stack_a);
	}
	else
	{
		while ((*stack_a)->element != min_value(*stack_a))
			ra(stack_a);
	}
}

void	do_opa(t_stack **stack_a, t_stack **stack_b)
{
	t_mynbr mynbr;
	int	tmp_a;
	int	pos_a;

	mynbr = get_min_op((*stack_a), (*stack_b));
	pos_a = pos_value_a((*stack_a), mynbr.nbr);
	tmp_a = calc_a((*stack_a), mynbr.nbr);
	while (tmp_a > 0)
	{
		if (mynbr.nbr < min_value(*stack_a))
		{
			check_min(stack_a, mynbr.nbr);
			tmp_a--;
		}
		else
		{
			while (tmp_a > 0)
			{
					if (pos_a > ft_stacksize((*stack_a)) / 2)
						rra(stack_a);
					else
						ra(stack_a);
				tmp_a--;
			}
		}
	}
}

void	algo(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stacksize(*stack_a) > 1)
		under_median(stack_a, stack_b);
	pa(stack_b, stack_a);
	while ((*stack_b))
	{
		db_op(stack_a, stack_b);
		do_opb(stack_a, stack_b);
		do_opa(stack_a, stack_b);
		pa(stack_b, stack_a);
	}
	check_min(stack_a, min_value(*stack_a));
}
