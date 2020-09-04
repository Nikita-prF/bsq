/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:26:06 by rjacqual          #+#    #+#             */
/*   Updated: 2020/08/12 18:53:39 by rjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	output_matrix(t_start *data)
{
	int		i;
	int		j;
	char	q;

	q = '\n';
	i = 0;
	while (i < data->col_line)
	{
		j = 0;
		while (j < data->size_line)
		{
			if (data->matrix[i][j] == 1)
				write(1, &(data->param[0]), 1);
			else if (data->matrix[i][j] == 0)
				write(1, &(data->param[1]), 1);
			else
				write(1, &(data->param[2]), 1);
			j++;
		}
		write(1, &q, 1);
		i++;
	}
}
