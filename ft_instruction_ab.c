/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:56:35 by msainton          #+#    #+#             */
/*   Updated: 2021/11/16 15:43:59 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap((*stack_a));
    swap((*stack_b));
    ft_putstr("ss");
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr("rr");
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse(stack_a);
    reverse(stack_a);
    ft_putstr("rrr");
}