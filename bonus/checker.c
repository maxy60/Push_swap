/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:21:39 by msainton          #+#    #+#             */
/*   Updated: 2021/12/08 11:50:32 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		stack = stack->next;
		free(stack->prec);
	}
	free(stack);
}

int	stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*last;

	if (!stack_a || stack_b)
	{
		ft_putstr("KO\n");
		return (0);
	}
	last = get_last_element(stack_a);
	while (stack_a->next && stack_a->element < stack_a->next->element)
		stack_a = stack_a->next;
	if (stack_a == last && !stack_b)
	{
		ft_putstr("OK\n");
		return (1);
	}
	else
	{
		ft_putstr("KO\n");
		return (0);
	}
}

int	checker(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	char	buff[1000];
	int		ret;

	while (1)
	{
		i = 0;
		while (i == 0 || (i > 0 && buff[i - 1] != '\n'))
		{
			ret = read(0, &buff[i], 1);
			i++;
			if (ret < -1)
				return (-1);
			if (ret == 0)
				return (stack_sort(*stack_a, *stack_b));
		}
		buff[i] = 0;
		if (check_do(stack_a, stack_b, buff) == -1)
		{
			ft_putstr("Error\n");
			return (-1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_var	list;
	int		i;

	if (argc == 1)
		return (0);
	i = 1;
	init(&list);
	stack_b = NULL;
	if (g_error(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	while (i < argc)
	{
		pushback(&list, ft_atoi(argv[i]));
		i++;
	}
	stack_a = list.first;
	checker(&stack_a, &stack_b);
	free_stack(stack_a);
}
