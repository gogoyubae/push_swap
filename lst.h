/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:13:46 by yubae             #+#    #+#             */
/*   Updated: 2021/06/18 18:32:41 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
#define LST_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct		s_node
{
	struct s_node	*prev;
	int				cont;
	struct s_node	*next;
}t_node;

typedef struct		s_list
{
	t_node			*head;
}t_list;

typedef struct		s_info
{
	t_list			*alist;
	t_list			*blist;
	int				max;
	int				min;
}t_info;

typedef	struct		s_val
{
	int				pa;
	int				pb;
	int				ra;
	int				rb;
}t_val;

t_node				*new_node();
void				push_swap(t_info *list);
void				push(t_list *list, int n);
void				rotate(t_list *list);
void				r_rotate(t_list *list);
void				pop(t_list *list);
void				swap(t_list *list);
int					count_node(t_list *list);
void				display(t_list *list);
void				sab(t_list *list);
void				pab(t_list *from, t_list *to);
void				rab(t_list *list);
void				rrab(t_list *list);
void				reverse(t_info *info, int i);
void				less5(t_info *info, int i);
void				node2(t_info *info);
void				node3(t_info *info);

/* less3 */

void				min(t_info *info, t_list *list);
void				max(t_info *info, t_list *list);
void				a_less3(t_info *info, int i);
void				a_node2(t_info *info);
void				a_node3(t_info *info);
void				b_less3(t_info *info, int i);
void				b_node2(t_info *info);
void				b_node3(t_info *info);

/* ft_atolli.c */
int					ft_atoi(const char *str);
long long int		ft_atolli(const char *str);
size_t				ft_strlen(const char *str);

/* qs.c*/
void				qs_swap(int *a, int *b);
int					qs_partition(int arr[], int l, int r);
void				quicksort(int arr[], int l, int r);

#endif
