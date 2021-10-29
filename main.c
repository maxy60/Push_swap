/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:46 by msainton          #+#    #+#             */
/*   Updated: 2021/10/29 17:55:07 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	b;
	int	c;
	int	D;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a	= NULL;
	stack_b = NULL;
	i = 1;
	c = 10;
	D = 1;
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
		i++;
	}
	while (D < i)
	{
		ft_put_list1(&stack_a, ft_atoi(argv[D]));
		D++;
	}
	pb(&stack_a, stack_b);
	//sa(stack_a);
	//ft_add_elem(&stack_a, c);
	while (stack_a->next != NULL)
	{
		ft_putnbr(stack_a->element);
		ft_putchar(' ');
		stack_a = stack_a->next;
	}
	ft_putnbr(stack_a->element);
	ft_putstr("ma stack_b\n");
	while (stack_b->next != NULL)
	{
		ft_putnbr(stack_b->element);
		ft_putchar(' ');
		stack_b = stack_b->next;
	}
	ft_putnbr(stack_b->element);
	return (0);
}
