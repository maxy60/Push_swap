/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_ab_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:56:35 by msainton          #+#    #+#             */
/*   Updated: 2021/12/08 10:08:49 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) >= 2)
		swap(*stack_a);
	if (ft_stacksize(*stack_b) >= 2)
		swap(*stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) >= 2)
		rotate(stack_a);
	if (ft_stacksize(*stack_b) >= 2)
		rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) >= 2)
		reverse(stack_a);
	if (ft_stacksize(*stack_b) >= 2)
		reverse(stack_b);
}
