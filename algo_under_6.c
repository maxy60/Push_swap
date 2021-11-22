/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_under_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:52:06 by msainton          #+#    #+#             */
/*   Updated: 2021/11/22 14:18:21 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    algo2(t_stack *stack_a)
{
    if (stack_a->element > stack_a->next->element)
        sa(stack_a);
}

void    algo3(t_stack **stack_a)
{
    if (((*stack_a)->element <= (*stack_a)->next->element) && 
    (*stack_a)->element <= (*stack_a)->next->next->element)
    {
        if ((*stack_a)->next->element > (*stack_a)->next->next->element)
        {
            sa((*stack_a));
            ra(stack_a);
        }
        return ;
    }
    if (((*stack_a)->element >= (*stack_a)->next->element) && 
    (*stack_a)->element >= (*stack_a)->next->next->element)
    {
        ra(stack_a);
        if ((*stack_a)->element > (*stack_a)->next->element)
            sa((*stack_a));
        return ;
    }
    else
    {
        if ((*stack_a)->next->element < (*stack_a)->element)
            sa((*stack_a));
        else
            rra(stack_a);
    }
}

int    lower(t_stack *stack)
{
    int a;
    
    a = stack->element;
    while (stack)
    {
        if (a > stack->element)
            a = stack->element;
        stack = stack->next;
    }
    return (a);
}

void    algo4(t_stack **stack_a, t_stack **stack_b)
{
    int a;

    a = lower((*stack_a));
    if ((*stack_a)->next->element == a)
        sa((*stack_a));
    else if ((*stack_a)->next->next->element == a)
    {
        rra(stack_a);
        rra(stack_a);
    }    
    else if ((*stack_a)->next->next->next->element == a)
        rra(stack_a);
    pa(stack_a, stack_b);
    algo3(stack_a);
    pb(stack_b, stack_a);
}

void    algo5(t_stack **stack_a, t_stack **stack_b)
{
    int a;
    
    a = lower((*stack_a));
    if ((*stack_a)->next->element == a)
        swap((*stack_a));
    else if ((*stack_a)->next->next->element == a)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if ((*stack_a)->next->next->next->element == a)
    {
        rra(stack_a);
        rra(stack_a);
    }    
    else if ((*stack_a)->next->next->next->next->element == a)
        rra(stack_a);
    pa(stack_a, stack_b);
    algo4(stack_a, stack_b);
    pb(stack_b, stack_a);
}