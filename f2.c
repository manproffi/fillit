/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:25:22 by sprotsen          #+#    #+#             */
/*   Updated: 2017/01/11 20:56:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	all_position(int *result, int *symb)
{
	int		i;
	int		**mass;

	i = 0;
	mass = (int**)malloc(sizeof(int*) * 2);
	mass[0] = (int*)malloc(sizeof(int) * symb[4]);
	mass[1] = (int*)malloc(sizeof(int) * symb[4]);
	while (i < symb[4])
	{
		mass[0][i] = result[i];
		mass[1][i] = 65 + i;
		i++;
	}
	free(result);
	next_function(symb, mass);
}

int		compare(int *row, t_list *l)
{
	while (l)
	{
		if (l->plc2 == row[1] - row[0] && l->plc3 == row[2] - row[0] &&
			l->plc4 == row[3] - row[0])
		{
			return (l->type);
		}
		l = l->next;
	}
	write(1, "error\n", 6);
	exit(0);
}

void	take_symblol(char *str, int *symb)
{
	int			row[7];
	int			*result;
	t_list		*list;

	row[4] = -1;
	row[5] = -1;
	row[6] = -1;
	list = etalon(4);
	result = (int*)malloc(sizeof(int) * symb[4]);
	if (!result)
		exit(EXIT_FAILURE);
	while (str[++row[4]])
	{
		if (str[row[4]] == '#')
			row[++row[5]] = row[4];
		if (row[5] == 3)
		{
			result[++row[6]] = compare(row, list);
			row[5] = -1;
		}
	}
	free(str);
	delete_list(list);
	all_position(result, symb);
}

int		n_element(int *symb)
{
	if (symb[4] == 1)
	{
		if (symb[0] != 12 || symb[1] != 4 || symb[2] != 4)
		{
			write(1, "error\n", 6);
			return (0);
		}
	}
	else
	{
		if (symb[0] != (12 * symb[4]) || (symb[1] != 4 * symb[4]) ||
			symb[2] != 4 * symb[4] + symb[4] - 1)
		{
			write(1, "error\n", 6);
			return (0);
		}
	}
	return (1);
}

int		validation_1(int *symb, int *count)
{
	if (symb[3] < 20)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	else if (symb[3] == 20)
		return (n_element(symb));
	else
	{
		while (*count != 20)
		{
			*count = *count - 21;
			symb[4]++;
		}
		if (symb[4] > 26)
		{
			write(1, "error\n", 6);
			exit(0);
		}
		return (n_element(symb));
	}
}
