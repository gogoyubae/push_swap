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

int		sorted(t_list *list)
{
	int		flag;
	int		compare;
	t_node	*tmp;
	t_node	*head;

	flag = 0;
	tmp = list->head;
	head = list->head;
	compare = tmp->cont;
	while (tmp->next != head)
	{
		tmp = tmp->next;
		if (compare > tmp->cont)
			return (flag);
	}
	flag = 1;
	return (flag);
}

int		r_sorted(t_list *list)
{
	int		flag;
	int		compare;
	t_node	*tmp;
	t_node	*head;

	flag = 0;
	tmp = list->head;
	head = list->head;
	compare = tmp->cont;
	while (tmp->next != head)
	{
		tmp = tmp->next;
		if (compare < tmp->cont)
			return (flag);
	}
	flag = 1;
	return (flag);
}

int		check_sorted(t_list *list)
{
	int	res;

	res = sorted(list);
	if (res == 1)
		return (1);
	res = r_sorted(list);
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

void	sort(t_info *info)
{
	int	i;

	if (check_sorted(tmp) == 1)
		return ;
	else
	{
		i = count_node(tmp);

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
	flag = check_sorted(tmp);
	if (flag == 1)
	{
		printf("already sorted");
		return ;
	}
	if (i == 3)
		node3(info);
	if (flag == -1)
	{
		printf("reverse sorted");
		reverse(info, i);
		return ;
	}
//	else
//		sort(info);
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

void		min3(t_info *info, t_list *list)
{
	int		i;
	int		k;
	int		min;
	t_node	*tmp;

	i = 0;
	k = 0;
	tmp = list->head;
	min = tmp->cont;
	while (k < 3)
	{
		tmp = tmp->next;
		if (min > tmp->cont)
		{
			min = tmp->cont;
			i++;
		}
		k++;
	}
	info->min = i;
}

void		max3(t_info *info, t_list *list)
{
	int		i;
	int		k;
	int		max;
	t_node	*tmp;

	i = 0;
	k = 0;
	tmp = list->head;
	max = tmp->cont;
	while (k < 3)
	{
		tmp = tmp->next;
		if (max < tmp->cont)
		{
			max = tmp->cont;
			i++;
		}
		k++;
	}
	info->max = i;
}
void		node3(t_info *info)
{
	min3(info, info->alist);
	max3(info, info->alist);
	if (info->min == 0 && info->max == 2)
		return ;
	else if (info->min == 0)
	{
		rrab(info->alist);
		sab(info->alist);
	}
	else if (info->min == 1 && info->max == 2)
		sab(info->alist);
	else if (info->min == 2 && info->max == 1)
		rrab(info->alist);
	else if (info->min == 2 && info->max == 0)
	{
		rab(info->alist);
		sab(info->alist);
	}
	else if (info->min == 1)
		rab(info->alist);
}

int		pivot(t_list *list)
{
	int		i;
	int 	pivot;
	int 	arr[500];
	t_list 	*tmp;

	i = 0;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		arr[i] = tmp->cont;
		tmp = tmp->next;
		i++;
	}
	quicksort(arr, 0, i - 1);
	pivot = arr[i / 2];
	return (pivot);
}
