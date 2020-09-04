/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:21:05 by rjacqual          #+#    #+#             */
/*   Updated: 2020/08/12 20:22:11 by rjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		mas(char *name, char *mas)
{
	int		f;
	int		i;
	char	ch;
	int		n;

	i = 0;
	n = 0;
	f = open(name, O_RDONLY);
	while (read(f, &ch, 1))
	{
		if (ch == '\n')
			n++;
		mas[i] = ch;
		i++;
	}
	mas[i] = '\0';
	close(f);
	return (n);
}

int		param(char *arg, char *param)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	g_g = 0;
	size = 0;
	while (arg[i] != '\n')
		i++;
	while (j < i - 3)
	{
		if (arg[j] < 48 || arg[j] > 57)
			return (0);
		size *= 10;
		size += arg[j] - 48;
		j++;
	}
	while (j < i)
	{
		param[g_g] = arg[j];
		g_g++;
		j++;
	}
	return (size);
}

int		prov_line(t_start *data, int i, int j, int old_size)
{
	int g;

	g = 0;
	data->matrix[i] = (int*)malloc((size_line(data->arg, j)) * sizeof(int));
	if (old_size != size_line(data->arg, j))
		return (-1);
	while (data->arg[j] != '\n')
	{
		if (data->param[0] == '\t' || data->param[1] == '\t' ||
			data->param[2] == '\t')
			return (-1);
		if (data->arg[j] != data->param[0] && data->arg[j] != data->param[1])
			return (-1);
		if (data->arg[j] == data->param[0])
			data->matrix[i][g] = 1;
		if (data->arg[j] == data->param[1])
			data->matrix[i][g] = 0;
		g++;
		j++;
	}
	return (j);
}

int		pars_mat(t_start *data)
{
	int j;
	int i;
	int size;

	j = 0;
	i = 0;
	while (data->arg[j] != '\n')
		j++;
	if (data->arg[j + 1] == '\n')
		return (0);
	size = size_line(data->arg, j + 1);
	data->size_line = size;
	while (i != data->col_line)
	{
		j++;
		j = prov_line(data, i, j, size);
		if (j == -1)
			return (0);
		i++;
	}
	return (1);
}

int		first(t_start *data, char *name)
{
	int n;

	if (size_gen(name) <= 0)
		return (0);
	data->arg = malloc(size_gen(name));
	n = mas(name, data->arg);
	data->col_line = param(data->arg, data->param);
	if (data->col_line <= 0)
		return (0);
	if (data->param[0] == data->param[1] || data->param[0] == data->param[2] ||
		data->param[1] == data->param[2])
		return (0);
	if (n - 1 != data->col_line)
		return (0);
	data->matrix = (int **)malloc(sizeof(int*) * data->col_line);
	if (!pars_mat(data))
		return (0);
	free(data->arg);
	return (1);
}
