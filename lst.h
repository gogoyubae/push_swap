/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:13:46 by yubae             #+#    #+#             */
/*   Updated: 2021/06/09 19:12:01 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
#define LST_H
#include <stdlib.h>
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
	int				min_idx;
	int				max_idx;
}t_info;

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
void				less5(t_info *info, int i);
void				node2(t_info *info);
void				node3(t_info *info);
#endif
