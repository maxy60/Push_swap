/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:36:40 by msainton          #+#    #+#             */
/*   Updated: 2021/10/26 18:08:53 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_put_list(t_list *lst, int element)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
//	if (!tmp)
//		return (NULL);
	tmp->element = element;
	tmp->next = lst;
	return (tmp);
}

void	ft_put_list1(t_list **lst, int element)
{
	t_list *elem;
	*lst = malloc(sizeof(t_list));
	(*lst)->element = element;
	elem->next = *lst;
	*lst = elem;
}