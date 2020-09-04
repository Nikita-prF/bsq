/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:14:52 by rjacqual          #+#    #+#             */
/*   Updated: 2020/08/12 20:19:58 by rjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	print_result(int ac, char **av, t_start *data)
{
	int i;

	i = 1;
	while (i < ac)
	{
		data = (t_start*)malloc(sizeof(t_start));
		if (ac > 2 && i != (ac - 1))
		{
			if (!first(data, av[i]))
				write(1, "map error\n", 10);
			else
				get_max_square(data);
			write(1, "\n", 1);
		}
		else
		{
			if (!first(data, av[i]))
				write(1, "map error\n", 10);
			else
				get_max_square(data);
		}
		free(data);
		i++;
	}
}
