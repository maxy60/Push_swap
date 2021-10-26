/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:48:27 by msainton          #+#    #+#             */
/*   Updated: 2021/10/26 13:52:57 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initialize_list(t_list *lst, int element)
{
	lst = (t_list *)malloc(sizeof(t_list));
	if(!lst)
		return ;
	lst->element = element;
	lst->next = NULL;
}
