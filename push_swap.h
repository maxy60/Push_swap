/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:21:57 by msainton          #+#    #+#             */
/*   Updated: 2021/10/26 16:03:36 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_list
{
	int	element;
	struct s_list *next;
	struct s_list *prec;
}	t_list;
/*typedef struct s_first
{
	s_list *premier;
}	t_first;
*/
t_list	*ft_put_list(t_list *lst, int element);
void	ft_put_list1(t_list **lst, int element);
int		main(int argc, char **argv);

#endif
