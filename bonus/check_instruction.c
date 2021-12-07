/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:06:16 by msainton          #+#    #+#             */
/*   Updated: 2021/12/07 21:22:02 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == ft_strlen(s1) && i == ft_strlen(s2))
		return (1);
	else
		return (0);
}

int	is_ok(char *buff)
{
	if (compare(buff, "sa\n") == 1 || compare(buff, "sb\n") == 1
		|| compare(buff, "ss\n") == 1 || compare(buff, "ra\n") == 1
		|| compare(buff, "rb\n") == 1 || compare(buff, "rr\n") == 1
		|| compare(buff, "rra\n") == 1 || compare(buff, "rrb\n") == 1
		|| compare(buff, "rrr\n") == 1 || compare(buff, "pa\n") == 1
		|| compare(buff, "pb\n") == 1)
		return (0);
	return (-1);
}

int	check_do(t_stack **stack_a, t_stack **stack_b, char *buff)
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
	else if (compare(buff, "rrb\n") == 1 && *stack_b)
		rrb(stack_b);
	else if (compare(buff, "rrr\n") == 1)
		rrr(stack_a, stack_b);
	else if (compare(buff, "pa\n") == 1)
		pa(stack_b, stack_a);
	else if (compare(buff, "pb\n") == 1)
		pb(stack_a, stack_b);
	else if (is_ok(buff) == -1)
		return (-1);
	return (0);
}
