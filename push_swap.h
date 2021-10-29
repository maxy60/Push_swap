/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:21:57 by msainton          #+#    #+#             */
/*   Updated: 2021/10/29 12:06:58 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_stack
{
	int	element;
	struct s_stack *next;
	struct s_stack *prec;
}	t_stack;

typedef struct s_var
{
	t_stack *a;
//	t_stack *b;
}	t_var;

t_stack	*ft_put_list(t_stack *lst, int element);
void	ft_put_list1(t_stack **lst, int element);
void	ft_add_elem(t_stack **lst, int c);
int		main(int argc, char **argv);

#endif
