/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsidiary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:05:56 by cshelli           #+#    #+#             */
/*   Updated: 2020/08/12 18:54:29 by rjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		size_gen(char *name)
{
	int		f;
	int		s;
	int		r;
	char	ch;

	s = 0;
	f = open(name, O_RDONLY);
	if (f < 0)
		return (0);
	while ((r = read(f, &ch, 1)))
	{
		if (r == -1)
			return (-1);
		s++;
	}
	close(f);
	return (s);
}

int		size_line(char *arg, int i)
{
	int sum;

	sum = 0;
	while (arg[i] != '\n')
	{
		i++;
		sum++;
	}
	return (sum);
}
