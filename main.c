/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:46 by msainton          #+#    #+#             */
/*   Updated: 2021/12/06 15:29:49 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	while (stack->next != NULL)
	{
		stack = stack->next;
		free(stack->prec);
	}
	free(stack);
}

void	chose_algo(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) == 2)
		algo2(*stack_a);
	else if (ft_stacksize(*stack_a) == 3)
		algo3(stack_a);
	else if (ft_stacksize(*stack_a) == 4)
		algo4(stack_a, stack_b);
	else if (ft_stacksize(*stack_a) == 5)
		algo5(stack_a, stack_b);
	else
		algo(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_var	list;
	t_mynbr	mynbr;

	stack_b = NULL;
	i = 1;
	init(&list);
	init1(&mynbr);
	if (g_error(argc, argv) == -1)
	{
		ft_putstr_fd("Error", 2);
		return (-1);
	}
	while (i < argc)
	{
		pushback(&list, ft_atoi(argv[i]));
		i++;
	}
	stack_a = list.first;
	chose_algo(&stack_a, &stack_b);
	free_stack(stack_a);
}
