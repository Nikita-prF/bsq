/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:56:24 by rjacqual          #+#    #+#             */
/*   Updated: 2020/08/12 18:47:49 by rjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		min(int a, int b, int c)
{
	int m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	ft_cash_tab(int **mx, int **bf, t_cntr *cnt, t_start *data)
{
	while (cnt->i < data->col_line)
	{
		bf[cnt->i][0] = mx[cnt->i][0];
		cnt->i++;
	}
	while (cnt->j < data->size_line)
	{
		bf[0][cnt->j] = mx[0][cnt->j];
		cnt->j++;
	}
	cnt->i = 1;
	while (cnt->i < data->col_line)
	{
		cnt->j = 1;
		while (cnt->j < data->size_line)
		{
			if (mx[cnt->i][cnt->j] == 1)
				bf[cnt->i][cnt->j] = min(bf[cnt->i][cnt->j - 1],
				bf[cnt->i - 1][cnt->j], bf[cnt->i - 1][cnt->j - 1]) + 1;
			else
				bf[cnt->i][cnt->j] = 0;
			cnt->j++;
		}
		cnt->i++;
	}
}

void	ft_find_max_entry(t_entry *max, int **bf, t_cntr *cnt, t_start *data)
{
	cnt->i = 0;
	while (cnt->i < data->col_line)
	{
		cnt->j = 0;
		while (cnt->j < data->size_line)
		{
			if (max->size < bf[cnt->i][cnt->j])
			{
				max->size = bf[cnt->i][cnt->j];
				max->i = cnt->i;
				max->j = cnt->j;
			}
			cnt->j++;
		}
		cnt->i++;
	}
	free(bf);
}

void	rebuild_map(int **mx, t_entry *max)
{
	int i;
	int j;
	int cnt;
	int cnt2;

	cnt = 0;
	i = max->i;
	j = max->j;
	while (cnt < max->size)
	{
		j = max->j;
		cnt2 = 0;
		while (cnt2 < max->size)
		{
			mx[i][j] = 2;
			cnt2++;
			j--;
		}
		i--;
		cnt++;
	}
	free(max);
}

void	get_max_square(t_start *data)
{
	int		g;
	t_cntr	cnt;
	t_entry	*max;
	int		**bf;

	cnt.i = 0;
	cnt.j = 0;
	g = 0;
	bf = (int**)malloc(sizeof(int*) * data->col_line);
	while (g < data->col_line)
	{
		bf[g] = (int *)malloc(data->size_line * sizeof(int));
		g++;
	}
	max = (t_entry*)malloc(sizeof(t_entry));
	ft_cash_tab(data->matrix, bf, &cnt, data);
	max->size = bf[0][0];
	max->i = 0;
	max->j = 0;
	ft_find_max_entry(max, bf, &cnt, data);
	rebuild_map(data->matrix, max);
	output_matrix(data);
}
