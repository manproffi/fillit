/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:32:50 by sprotsen          #+#    #+#             */
/*   Updated: 2017/01/11 20:56:35 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	build_mass_p(struct s_list **pp, t_list *k_l, t_list *copy, int **mass)
{
	t_list		*list;
	int			i;
	int			len;

	len = ft_lstsize(k_l);
	i = -1;
	while (++i < len)
	{
		list = copy;
		while (list)
		{
			if (mass[0][i] == list->type)
			{
				k_l->type = list->type;
				k_l->plc2 = list->plc2;
				k_l->plc3 = list->plc3;
				k_l->plc4 = list->plc4;
				k_l->smb = mass[1][i];
				pp[i] = k_l;
				k_l = k_l->next;
			}
			list = list->next;
		}
	}
}

void	add_tetramino(struct s_list **p, int *symb, char *row, int *len_row)
{
	int		i;
	int		k;

	k = 0;
	while (k < symb[4])
	{
		i = p[k]->ind - 1;
		while (row[++i])
			if (row[i] == '.' && row[i + p[k]->plc2] == '.' &&
			row[i + p[k]->plc3] == '.' && row[i + p[k]->plc4] == '.')
			{
				row[i] = p[k]->smb;
				row[i + p[k]->plc2] = p[k]->smb;
				row[i + p[k]->plc3] = p[k]->smb;
				row[i + p[k]->plc4] = p[k]->smb;
				p[k]->ind = i;
				break ;
			}
		if (i == *len_row)
		{
			p[k]->ind = i;
			break ;
		}
		k++;
	}
}

void	delete_element(char *row, int *symb)
{
	symb[0] = 0;
	while (row[symb[0]])
	{
		if (row[symb[0]] >= 65 && row[symb[0]] <= 90)
			row[symb[0]] = '.';
		symb[0]++;
	}
}

void	new_etalon_reassignment(struct s_list **p, int i, t_list *list)
{
	p[i]->plc2 = list->plc2;
	p[i]->plc3 = list->plc3;
	p[i]->plc4 = list->plc4;
	p[i]->ind = 0;
}

void	new_etalon(struct s_list **p, int *symb)
{
	t_list	*list;
	t_list	*copy;
	char	*row;
	int		length_row;

	symb[0] = ++symb[5] + ft_sqrt_mod_fillit(symb[4] * 4);
	symb[1] = -1;
	copy = etalon(symb[0]);
	row = create_row(symb[0]);
	length_row = ft_strlen(row);
	while (++symb[1] < symb[4])
	{
		list = copy;
		while (list)
		{
			if (p[symb[1]]->type == list->type)
			{
				new_etalon_reassignment(p, symb[1], list);
				break ;
			}
			list = list->next;
		}
	}
	delete_list(copy);
	building_map(p, symb, row, &length_row);
}
