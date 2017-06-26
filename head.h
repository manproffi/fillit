/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:21:16 by sprotsen          #+#    #+#             */
/*   Updated: 2017/01/11 20:59:04 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	int				type;
	int				plc2;
	int				plc3;
	int				plc4;
	int				smb;
	int				ind;
	struct s_list	*next;
}					t_list;

int					validation_1(int *symb, int *count);
int					n_element(int *symb);
void				take_symblol(char *str, int *symb);
void				all_position(int *result, int *symb);
void				next_function(int *symb, int **mass);
void				delete_list(t_list *list);
void				buil(struct s_list **p, int *symb);
void				building_map(struct s_list **p, int *symb,
					char *row, int *len_row);
int					correct(struct s_list **p, int *length_row, int *symb,
					char *row);
void				new_etalon(struct s_list **p, int *symb);
void				delete_element(char *row, int *symb);
void				add_tetramino(struct s_list **p, int *symb, char *row,
					int *len_row);
void				build_mass_p(struct s_list **pp, t_list *k_l, t_list *copy,
					int **mass);
int					ft_sqrt_mod_fillit(int num);
int					ft_sqrt(int nb);
char				*create_row(int n_square);
t_list				*etalon(int n);
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew_1(int ty, int p2, int p3, int p4);
int					ft_lstsize(t_list *begin_list);
int					ft_strlen(const char *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);

#endif
