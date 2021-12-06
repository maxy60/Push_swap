/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_error_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <msainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:04:19 by msainton          #+#    #+#             */
/*   Updated: 2021/12/06 20:03:26 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	g_error(int argc, char **argv)
{
	int	i;
	int	b;

	i = 1;
	while (i < argc)
	{
		b = 0;
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648
			|| max_value(argv[i]) == 1 || db_nbr(i, argc, argv) == 1)
			return (-1);
		if (argv[i][b] == '-' || argv[i][b] == '+')
			b++;
		if (argv[i][0] == 0)
			return (-1);
		while (argv[i][b])
		{
			if (argv[i][b] < '0' || argv[i][b] > '9')
				return (-1);
			b++;
		}
		i++;
	}
	return (0);
}
