/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:46 by msainton          #+#    #+#             */
/*   Updated: 2021/11/02 17:34:04 by msainton         ###   ########.fr       */
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

	stack_a	= NULL;
	stack_b = NULL;
	i = 1;
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
		ft_put_list1(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	rotate(&stack_a);
//	push(&stack_a, &stack_b);
//	printf("good eveningn");
	//swap(stack_a);
	//ft_add_elem(&stack_a, c);
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
