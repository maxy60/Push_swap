/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:36:40 by msainton          #+#    #+#             */
/*   Updated: 2021/11/10 14:53:55 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_var *l)
{
	l->first = NULL;
	l->last = NULL;
}

void	pushback(t_var *l, int element)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	stack->element = element;
	stack->prec = l->last;
	stack->next = NULL;
	if (l->last)
		l->last->next = stack;
	else
		l->first = stack;
	l->last = stack;
}

void	pushfront(t_var *l, int element)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	stack->element = element;
	stack->next = l->first;
	stack->prec = NULL;
	if(l->first)
		l->first->prec = stack;
	else
		l->last = stack;
	l->first = stack;
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
