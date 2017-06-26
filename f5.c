/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:35:57 by sprotsen          #+#    #+#             */
/*   Updated: 2017/01/11 20:56:40 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

t_list	*etalon(int n)
{
	t_list	*list;

	list = ft_lstnew_1(100, n + 1, 2 * n + 2, 3 * n + 3);
	ft_lstadd(&(list), ft_lstnew_1(101, 1, 2, 3));
	ft_lstadd(&(list), ft_lstnew_1(102, 1, n + 1, n + 2));
	ft_lstadd(&(list), ft_lstnew_1(103, 1, n + 2, n + 3));
	ft_lstadd(&(list), ft_lstnew_1(104, n, n + 1, 2 * n + 1));
	ft_lstadd(&(list), ft_lstnew_1(105, 1, n, n + 1));
	ft_lstadd(&(list), ft_lstnew_1(106, n + 1, n + 2, 2 * n + 3));
	ft_lstadd(&(list), ft_lstnew_1(107, n, n + 1, n + 2));
	ft_lstadd(&(list), ft_lstnew_1(108, n, n + 1, 2 * n + 2));
	ft_lstadd(&(list), ft_lstnew_1(109, n + 1, n + 2, 2 * n + 2));
	ft_lstadd(&(list), ft_lstnew_1(110, 1, 2, n + 2));
	ft_lstadd(&(list), ft_lstnew_1(111, n - 1, n, n + 1));
	ft_lstadd(&(list), ft_lstnew_1(112, 1, n + 2, 2 * n + 3));
	ft_lstadd(&(list), ft_lstnew_1(113, 1, 2, n + 1));
	ft_lstadd(&(list), ft_lstnew_1(114, n + 1, 2 * n + 2, 2 * n + 3));
	ft_lstadd(&(list), ft_lstnew_1(115, 1, 2, n + 3));
	ft_lstadd(&(list), ft_lstnew_1(116, n + 1, 2 * n + 1, 2 * n + 2));
	ft_lstadd(&(list), ft_lstnew_1(117, n + 1, n + 2, n + 3));
	ft_lstadd(&(list), ft_lstnew_1(118, 1, n + 1, 2 * n + 2));
	return (list);
}

char	*create_row(int n_square)
{
	char	*row;
	int		i;
	int		len;
	int		k;

	i = 0;
	len = n_square * n_square + n_square;
	k = n_square;
	if (!(row = (char*)malloc(sizeof(char) * (len + 1))))
	{
		write(1, "error with memory\n", 18);
		exit(1);
	}
	row[len] = '\0';
	while (i < len)
		if (i == k)
		{
			row[i++] = '\n';
			k = k + n_square + 1;
		}
		else
			row[i++] = '.';
	return (row);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i++ <= 121)
	{
		if (i * i == nb)
			return (i);
	}
	return (0);
}

int		ft_sqrt_mod_fillit(int num)
{
	int i;

	i = 1;
	while (num <= 121)
	{
		if (ft_sqrt(num))
			return (ft_sqrt(num));
		num++;
	}
	return (0);
}
