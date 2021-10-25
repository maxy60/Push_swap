/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:36:40 by msainton          #+#    #+#             */
/*   Updated: 2021/10/25 19:34:36 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_list(t_list **lst, int element)
{
	t_list *elem;
	t_list *last;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return ;
	elem->element = element;
	elem->next = NULL;
	if ((*lst) == NULL)
		*lst = elem;
	
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = elem;
	}
}
