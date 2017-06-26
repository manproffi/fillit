/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:27:09 by sprotsen          #+#    #+#             */
/*   Updated: 2017/01/11 20:56:25 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		correct(struct s_list **p, int *length_row, int *symb, char *row)
{
	symb[0] = 0;
	symb[2] = symb[4] - 1;
	if (p[0]->ind >= *length_row - p[0]->plc4 + 1)
	{
		free(row);
		new_etalon(p, symb);
	}
	while (symb[2] > 0)
	{
		if (p[symb[2]]->ind >= *length_row)
		{
			p[symb[2]]->ind = 0;
			p[symb[2] - 1]->ind += 1;
			symb[0]++;
		}
		symb[2]--;
	}
	if (symb[0] == 0)
		return (1);
	return (0);
}

void	building_map(struct s_list **p, int *symb, char *row, int *len_row)
{
	add_tetramino(p, symb, row, len_row);
	while (correct(p, len_row, symb, row) == 0)
	{
		delete_element(row, symb);
		add_tetramino(p, symb, row, len_row);
	}
	ft_putstr(row);
	free(row);
	exit(0);
}

void	buil(struct s_list **p, int *symb)
{
	char	*row;
	int		length_row;

	row = create_row(ft_sqrt_mod_fillit(symb[4] * 4));
	symb[5] = 0;
	symb[3] = 0;
	length_row = ft_strlen(row);
	building_map(p, symb, row, &length_row);
}

void	delete_list(t_list *list)
{
	if (list)
	{
		delete_list(list->next);
		free(list);
		list = NULL;
	}
}

void	next_function(int *symb, int **mass)
{
	t_list			*k_l;
	t_list			*copy;
	struct s_list	*p[symb[4]];
	int				i;

	i = -1;
	copy = etalon(ft_sqrt_mod_fillit(symb[4] * 4));
	k_l = ft_lstnew_1(0, 0, 0, 0);
	while (++i < symb[4] - 1)
		ft_lstadd(&(k_l), ft_lstnew_1(0, 0, 0, 0));
	build_mass_p(p, k_l, copy, mass);
	delete_list(copy);
	free(mass[0]);
	free(mass[1]);
	free(mass);
	buil(p, symb);
}
