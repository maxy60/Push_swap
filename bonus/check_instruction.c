/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:06:16 by msainton          #+#    #+#             */
/*   Updated: 2021/12/06 20:10:41 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] == s2[i])
		i++;
	if (i == ft_strlen(s1) && i == ft_strlen(s2))
		return (1);
	else
		return (0);
}

int	check_do(char *buff, t_stack **stack_a, t_stack **stack_b)
{
	if (compare(buff, "sa\n") == 1)
		sa(*stack_a);
	else if (compare(buff, "sb\n") == 1)
		sb(*stack_b);
	else if (compare(buff, "ss\n") == 1)
		ss(stack_a, stack_b);
	else if (compare(buff, "ra\n") == 1)
		ra(stack_a);
	else if (compare(buff, "rb\n") == 1)
		rb(stack_b);
	else if (compare(buff, "rr\n") == 1)
		rr(stack_a, stack_b);
	else if (compare(buff, "rra\n") == 1)
		rra(stack_a);
	else if (compare(buff, "rrb\n") == 1)
		rrb(stack_b);
	else if (compare(buff, "rrr\n") == 1)
		rrr(stack_a, stack_b);
	else if (compare(buff, "pa\n") == 1)
		pa(stack_a, stack_b);
	else if (compare(buff, "pb\n") == 1)
		pb(stack_b, stack_a);
	else
		return (-1);
	return (0);
}



