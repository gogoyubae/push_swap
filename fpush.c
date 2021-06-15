/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:04:43 by yubae             #+#    #+#             */
/*   Updated: 2021/06/15 16:04:50 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int		sorted(t_list *list, int i)
{
	int		flag;
	int		node;
	int		compare;
	t_node	*tmp;
	t_node	*head;

	flag = 0;
	node = 1;
	tmp = list->head;
	head = list->head;
	compare = tmp->cont;
	while (tmp->next != head)
	{
		tmp = tmp->next;
		if (compare < tmp->cont)
		{
			compare = tmp->cont;
			node++;
		}
	}
	if (node == i)
		flag = 1;
	return (flag);
}

int		r_sorted(t_list *list, int i)
{
	int		flag;
	int		node;
	int		compare;
	t_node	*tmp;
	t_node	*head;

	flag = 0;
	node = 1;
	tmp = list->head;
	head = list->head;
	compare = tmp->cont;
	while (tmp->next != head)
	{
		tmp = tmp->next;
		if (compare > tmp->cont)
		{
			compare = tmp->cont;
			node++;
		}
	}
	if (node == i)
		flag = 1;
	return (flag);
}

int		check_sorted(t_list *list, int i)
{
	int	res;

	res = sorted(list, i);
	if (res == 1)
		return (1);
	res = r_sorted(list, i);
	if (res == 1)
		return (-1);
	else
		return (0);
}

void	reverse(t_info *info, int i)
{
	t_list	*a;
	t_list	*b;
	int		n;

	a = info->alist;
	b = info->blist;
	n = 2;
	while (n < i)
	{
		pab(a, b);
		n++;
	}
	sab(a);
	while (b->head != 0)
	{
		pab(b, a);
		rab(a);
	}
}

void	push_swap(t_info *info)
{
	int	i;
	int	flag;
	t_list *tmp;

	tmp = info->alist;
	i = count_node(tmp);
	if (i == 0 || i == 1)
		return ;
	flag = check_sorted(tmp, i);
	if (flag == 1)
	{
		printf("already sorted");
		return ;
	}
	if (flag == -1 && i == 5)
	{
		printf("reverse sorted");
		reverse(info, i);
		return ;
	}
	else if (i <= 5)
		less5(info, i);
}

void	less5(t_info *info, int i)
{
	if (i == 2)
		node2(info);
	else if (i == 3)
		node3(info);
//	else if (i == 5)
//		node_5(list);
	return ;
}

void		node2(t_info *info)
{
	int		node1;
	int		node2;
	t_list	*list;
	t_node	*tmp;

	list = info->alist;
	tmp = list->head;
	node1 = tmp->cont;
	tmp = tmp->next;
	node2 = tmp->cont;

	if (node1 > node2)
		sab(list);
	return ;
}

void		node3(t_info *info)
{
	int	min_idx;
	int max_idx;

	min_idx = info->min_idx;
	max_idx = info->max_idx;
	if (min_idx == 0)
	{
		rrab(info->alist);
		sab(info->alist);
	}
	else if (min_idx == 1 && max_idx == 2)
		sab(info->alist);
	else if (min_idx == 2 && max_idx == 1)
		rrab(info->alist);
	else if (min_idx == 2 && max_idx == 0)
	{
		rab(info->alist);
		sab(info->alist);
	}
	else if (min_idx == 1)
		rab(info->alist);
}
