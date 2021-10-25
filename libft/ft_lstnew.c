/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:15:25 by msainton          #+#    #+#             */
/*   Updated: 2021/06/14 10:55:31 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t1;

	t1 = (t_list *)malloc(sizeof(t_list) * 1);
	if (!t1)
		return (NULL);
	t1->content = content;
	t1->next = NULL;
	return (t1);
}
