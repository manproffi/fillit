/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:23:09 by sprotsen          #+#    #+#             */
/*   Updated: 2017/01/11 20:56:09 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		validation_2(char *str, int length)
{
	int		i;

	i = 20;
	if (length > 20)
	{
		while (i < length - 1)
		{
			if (str[i] == '\n')
				i += 21;
			else
			{
				write(1, "error\n", 6);
				exit(0);
			}
		}
		if (i == length)
			return (1);
		write(1, "error\n", 6);
		exit(0);
	}
	return (1);
}

void	validation(char *str, int *count)
{
	int		symb[6];

	symb[0] = 0;
	symb[1] = 0;
	symb[2] = 0;
	symb[3] = 0;
	symb[4] = 1;
	while (str[symb[3]])
	{
		if (str[symb[3]] == '.')
			symb[0]++;
		else if (str[symb[3]] == '#')
			symb[1]++;
		else if (str[symb[3]] == '\n')
			symb[2]++;
		else
		{
			write(1, "error\n", 6);
			exit(0);
		}
		symb[3]++;
	}
	if (validation_2(str, symb[3]))
		validation_1(symb, count) ? take_symblol(str, symb) : exit(0);
}

void	for_read(int argc, char **argv, char *str, int *count)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error - cannot open file\n", 25);
		exit(EXIT_FAILURE);
	}
	while (read(fd, &c, 1))
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	close(fd);
	validation(str, count);
}

void	open_file(int argc, char **argv)
{
	int		fd;
	int		count;
	char	c;
	char	*str;

	count = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error - cannot open file\n", 25);
		exit(EXIT_FAILURE);
	}
	while (read(fd, &c, 1))
		count++;
	str = (char*)malloc(sizeof(char) * count + 1);
	if (!str)
	{
		write(1, "Error with memory\n", 18);
		exit(EXIT_FAILURE);
	}
	str[count] = '\0';
	close(fd);
	for_read(argc, argv, str, &count);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		open_file(argc, argv);
	return (0);
}
