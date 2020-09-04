/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:43:44 by rjacqual          #+#    #+#             */
/*   Updated: 2020/08/12 18:49:00 by rjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_LIB_H
# define BSQ_LIB_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct
{
	int		col_line;
	int		size_line;
	char	*arg;
	char	param[3];
	int		**matrix;
}			t_start;

typedef struct
{
	int		size;
	int		i;
	int		j;
}			t_entry;

typedef struct
{
	int		i;
	int		j;
}			t_cntr;

int			g_g;
int			g_i;
int			size_gen(char *name);
int			size_line(char *arg, int i);
int			mas(char *name, char *mas);
int			param(char *arg, char *param);
int			prov_line(t_start *data, int i, int j, int old_size);
int			pars_mat(t_start *data);
int			first(t_start *data, char *name);
int			min(int a, int b, int c);
void		ft_cash_tab(int **mx, int **bf, t_cntr *cnt, t_start *data);
void		ft_find_max_entry(t_entry *max, int **bf,
			t_cntr *cnt, t_start *data);
void		rebuild_map(int **mx, t_entry *max);
void		get_max_square(t_start *data);
void		output_matrix(t_start *data);
void		term(t_start *data);
void		print_result(int ac, char **av, t_start *data);

#endif
