/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:49:32 by msainton          #+#    #+#             */
/*   Updated: 2021/10/29 17:53:45 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int a;

	a = stack_a->element;
	stack_a->element = stack_a->next->element;
	stack_a->next->element = a;
}

void	pb(t_stack **stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = *stack_a;
	stack_b = tmp;
	stack_b->next = NULL;
}
