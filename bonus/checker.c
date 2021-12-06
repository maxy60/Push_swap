/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:21:39 by msainton          #+#    #+#             */
/*   Updated: 2021/12/06 21:35:51 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack *stack)
{
	while (stack->next != NULL)
	{
		stack = stack->next;
		free(stack->prec);
	}
	free(stack);
}

int	stack_sort(t_stack *stack)
{
	while (stack->element < stack->next->element)
			stack = stack->next;
	if (get_last_element(stack) == stack)
		return (1);
	else
		return (0);
}

int	checker(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	char	buff[5];
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
			if (ret = 0)
				return (0);
		}
		buff[i] = 0;
		check_do(buff, stack_a, stack_b);
	}
}

static void print_stack_bon_sens(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d ", stack->element);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int		i;
    t_stack *stack_a;
    t_stack *stack_b;
	t_var	list;
	i = 1;
	init(&list);
	stack_b = NULL;
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
	checker(&stack_a, &stack_b);
	return (0);
	if (stack_sort(stack_a) == 1 && !stack_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(stack_a);
}
