/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f6.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:37:29 by sprotsen          #+#    #+#             */
/*   Updated: 2017/01/11 20:56:49 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
			ft_putchar(*s++);
	}
}

int		ft_strlen(const char *s)
{
	int		count;

	count = 0;
	while (*s++ != '\0')
		count++;
	return (count);
}

int		ft_lstsize(t_list *begin_list)
{
	int		count;
	t_list	*list;

	count = 0;
	list = begin_list;
	if (list)
	{
		while (list)
		{
			count++;
			list = list->next;
		}
		return (count);
	}
	else
		return (0);
}

t_list	*ft_lstnew_1(int ty, int p2, int p3, int p4)
{
	t_list		*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->type = ty;
	list->plc2 = p2;
	list->plc3 = p3;
	list->plc4 = p4;
	list->smb = 0;
	list->ind = 0;
	list->next = NULL;
	return (list);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = (*alst);
	(*alst) = new;
}
