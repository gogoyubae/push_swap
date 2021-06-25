/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:13:46 by yubae             #+#    #+#             */
/*   Updated: 2021/06/25 18:34:08 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
#define LST_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
	int				node;
}t_info;

typedef	struct		s_val
{
	int				pa;
	int				pb;
	int				ra;
	int				rb;
}t_val;

/* node */
t_node				*new_node(void);
int					count_node(t_list *list);

/* basiclist */
void				push(t_list *list, int n);
void				rotate(t_list *list);
void				r_rotate(t_list *list);
void				pop(t_list *list);
void				swap(t_list *list);

/* numlist */
int					me_isdigit(char c);
int					checkint(char *num);
int					samenum(int argc, int *arr);
int					*copylist(int argc, char *argv[]);
void				initlist(t_list *list, int argc, int *arr);

/* push_swap */
int					sorted(t_list *list);
int					r_sorted(t_list *list);
int					check_sorted(t_list *list);
void				reverse(t_info *info, int i);
void				push_swap(t_info *info);

/* x2x */
void				init_val(t_val *val);
t_val				a2b_sort(t_list *a, t_list *b, int cnt, int p);
void				a2b(t_info *info, t_list *a, t_list *b, int cnt);
t_val				b2a_sort(t_list *a, t_list *b, int cnt, int p);
void				b2a(t_info *info, t_list *a, t_list *b, int cnt);

/* a_cmd */
void				sa(t_list *list);
void				pa(t_list *from, t_list *to);
void				ra(t_list *list);
void				rra(t_list *list);

/* b_cmd */
void				sb(t_list *list);
void				pb(t_list *from, t_list *to);
void				rb(t_list *list);
void				rrb(t_list *list);

/* less3 */
void				min(t_info *info, t_list *list);
void				max(t_info *info, t_list *list);
void				a_less3(t_info *info, int i);
void				a_node2(t_info *info);
void				a_node3(t_info *info);
void				b_less3(t_info *info, int i);
void				b_node2(t_info *info);
void				b_node3(t_info *info);

/* ft_atolli */
int					ft_atoi(const char *str);
long long int		ft_atolli(const char *str);
size_t				ft_strlen(const char *str);
void				ft_putstr(char *str);

/* qs*/
void				qs_swap(int *a, int *b);
int					qs_partition(int arr[], int l, int r);
void				quicksort(int arr[], int l, int r);
int					pivot(t_list *list, int cnt);

/* display */
void				display(t_list *list);

#endif
