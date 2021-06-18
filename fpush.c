/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:04:43 by yubae             #+#    #+#             */
/*   Updated: 2021/06/18 16:47:46 by yubae            ###   ########.fr       */
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

// void		sort(t_info *info)
// {
// 	int		i;
// 	int		pivot;
// 	t_list	a;
// 	t_list	b;

// 	a = info->alist;
// 	b = info->blist;
// 	i = count_node(a);
// 	if (i <= 3)
// 	{
// 		a_less3(info);
// 		b_less3(info);
// 		while (i--)
// 			pab(b, a);
// 		return ;
// 	}
// 	else
// 	{
// 		pivot = pivot(a);
// 		if (pivot > a->cont)
// 			rab(a);
// 		else
// 			pab(a, b);
// 		i = count_node(a);
// 		sort(info);
// 	}

// }

void	a2b(t_list *a, t_list *b, int cnt)
{
	int	i;
	int	p;
	int cnt;

	if (sorted(a) && b == 0)
		return ;
	if (cnt <= 3)
	{
		a_less3(info);
		b_less3(info);
		while (cnt--)
			pab(b, a);
	}
	else
	{
		a2b(~~~);
		b2a(~~~);
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
	else
		sort(info);
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
