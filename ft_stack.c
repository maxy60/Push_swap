/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:36:40 by msainton          #+#    #+#             */
/*   Updated: 2021/11/02 17:10:58 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*ft_stacknew(int content)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->element = content;
	stack->next = NULL;
	return(stack);
}

void	ft_put_list1(t_stack **lst, int element)
{
	t_stack *tmp;
	t_stack *test;
	test = malloc(sizeof(t_stack));
	test->element = element;
	test->next = NULL;
	if (*lst == NULL)
		*lst = test;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = test;
	}
}

void	ft_add_elem(t_stack **lst, int c)
{
	t_stack *new;
	t_stack *tmp;
	t_stack *conserv;

	tmp = *lst;
	new = malloc(sizeof(t_list));
	new->element = c;
	while (tmp->next != NULL)
	{
		if (new->element >= tmp->element)
		{
			conserv = tmp->next;
			tmp->next = new;
			new->next = conserv;
		}
		tmp = tmp->next;
	}
}
