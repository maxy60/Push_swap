/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:17:46 by msainton          #+#    #+#             */
/*   Updated: 2021/10/26 16:49:47 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	t_list *lst;

	lst = NULL;
	a = 1;
	while (a < argc)
	{
		b = 0;
		if (argv[a][b] == '-' || argv[a][b] == '+')
			b++;
		while (argv[a][b])
		{
			if (argv[a][b] < '0' || argv[a][b] > '9')
			{
				printf("Error");
				return (1);
			}
			b++;
		}
		ft_put_list1(&lst, ft_atoi(argv[a]));
	//	lst = ft_put_list(lst, ft_atoi(argv[a]));
		a++;
	}
	printf("%d %d %d\n", lst->element, lst->next->element, lst->next->next->element);
	return (0);
}
