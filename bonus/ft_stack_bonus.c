/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:36:40 by msainton          #+#    #+#             */
/*   Updated: 2021/12/06 19:47:41 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init(t_var *l)
{
	l->first = NULL;
	l->last = NULL;
}

void	init1(t_mynbr *nbr)
{
	nbr->nbr = 0;
	nbr->count = 0;
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
