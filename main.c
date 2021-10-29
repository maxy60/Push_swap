/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:46 by msainton          #+#    #+#             */
/*   Updated: 2021/10/29 14:14:51 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	b;
	int	c;
	t_stack *stack_a;
//	t_stack *stack_b;

   stack_a	= NULL;
	i = 1;
	c = 10;
	while (i < argc)
	{
		b = 0;
		if (argv[i][b] == '-' || argv[i][b] == '+')
			b++;
		while (argv[i][b])
		{
			if (argv[i][b] < '0' || argv[i][b] > '9')
			{
				ft_putstr_fd("Error", 2);
				return (1);
			}
			b++;
		}
		ft_put_list1(&stack_a, ft_atoi(argv[i]));
		ft_putchar(' ');
		i++;
	}
	ft_add_elem(&stack_a, c);
	return (0);
}
