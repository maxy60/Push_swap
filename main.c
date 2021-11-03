/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:46 by msainton          #+#    #+#             */
/*   Updated: 2021/11/03 15:53:35 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	b;
	t_stack *stack_a;
	t_stack *stack_b;
	t_var	list;

	stack_b = NULL;
	i = 1;
	init(&list);
	while (i < argc)
	{
		b = 0;
		if (argv[i][b] == '-' || argv[i][b] == '+')
			b++;
		if (argv[i][0] == 0)
		{
			ft_putstr_fd("Error", 2);
			return (-1);
		}
		while (argv[i][b])
		{
			if (argv[i][b] < '0' || argv[i][b] > '9')
			{
				ft_putstr_fd("Error", 2);
				return (-1);
			}
			b++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		pushback(&list, ft_atoi(argv[i]));
		i++;
	}
	stack_a	= list.first;
//	inverse(&list.last);
//	rotate(&stack_a);
//	push(&stack_a, &stack_b);
//	swap(stack_a);
	while (stack_a != NULL)
	{
		ft_putnbr(stack_a->element);
		ft_putchar(' ');
		stack_a = stack_a->next;
	}
	printf("\n");
//	while (stack_b != NULL)
//	{
//		ft_putnbr(stack_b->element);
//		ft_putchar(' ');
//		stack_b = stack_b->next;
//	}
	return (0);
}
