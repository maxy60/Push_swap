/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:36:40 by msainton          #+#    #+#             */
/*   Updated: 2021/10/29 14:14:49 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_put_list(t_stack *lst, int element)
{
	t_stack *tmp;

	tmp = malloc(sizeof(t_list));
//	if (!tmp)
//		return (NULL);
	tmp->element = element;
	tmp->next = lst;
	return (tmp);
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
		ft_putnbr(tmp->element);
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
