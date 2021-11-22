/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:46 by msainton          #+#    #+#             */
/*   Updated: 2021/11/19 01:04:13 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	db_nbr(int i, int ac, char **av)
{
	int	j;
	int	k;

	j = i;
	k = i + 1;
	while (k < ac)
	{
		if (ft_atoi(av[j]) == ft_atoi(av[k]))
			return (1);
		k++;
	}
	return (0);
}

int	max_value(char *str)
{
	int	a;

	a = ft_strlen(str);

	if (a >= 11)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	b;
	t_stack *stack_a;
	t_stack *stack_b;
	t_var	list;
	t_mynbr	mynbr;

	stack_b = NULL;
	i = 1;
	init(&list);
	init1(&mynbr);
	while (i < argc)
	{
		b = 0;
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648
				|| max_value(argv[i]) == 1 || db_nbr(i, argc, argv) == 1)
		{
			ft_putstr_fd("Error", 2);
			return (-1);
		}
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
	if (ft_stacksize(stack_a) == 2)
		algo2(stack_a);
	else if (ft_stacksize(stack_a) == 3)
		algo3(&stack_a);
	else if (ft_stacksize(stack_a) == 4)
		algo4(&stack_a, &stack_b);
	else if (ft_stacksize(stack_a) == 5)
		algo5(&stack_a, &stack_b);
	else
		algo(&stack_a, &stack_b);
	printf("\nSTACK_A\n");
	while (stack_a != NULL)
	{
		ft_putnbr(stack_a->element);
		ft_putchar(' ');
		stack_a = stack_a->next;
	}
	printf("\nSTACK_B\n");
	if (stack_b)
	{
		while (stack_b != NULL)
		{
			ft_putnbr(stack_b->element);
			ft_putchar(' ');
			stack_b = stack_b->next;
		}
	}
	return (0);
}
