/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshelli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:33:23 by cshelli           #+#    #+#             */
/*   Updated: 2020/08/12 20:33:25 by cshelli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void		term(t_start *data)
{
	int		f;
	char	ch;

	data = (t_start*)malloc(sizeof(t_start));
	f = open("buff", O_TRUNC);
	f = open("buff", O_WRONLY);
	while (read(0, &ch, 1))
		write(f, &ch, 1);
	close(f);
	if (!first(data, "buff"))
		write(1, "\nmap error\n", 10);
	else
		get_max_square(data);
}
