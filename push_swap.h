/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:21:57 by msainton          #+#    #+#             */
/*   Updated: 2021/10/25 19:34:39 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_list
{
	int	element;
	struct s_list *next;
}	t_list;

void	ft_put_list(t_list **lst, int element);
int		main(int argc, char **argv);

#endif
