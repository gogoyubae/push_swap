/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:04:43 by yubae             #+#    #+#             */
/*   Updated: 2021/06/25 18:33:51 by yubae            ###   ########.fr       */
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
	while (tmp->next != head)
	{
		compare = tmp->cont;
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
	while (tmp->next != head)
	{
		compare = tmp->cont;
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
		pb(a, b);
		n++;
	}
	sa(a);
	while (b->head != 0)
	{
		pa(b, a);
		ra(a);
	}
}

void		push_swap(t_info *info)
{
	int		i;
	int		flag;
	t_list	*tmp;

	tmp = info->alist;
	i = count_node(tmp);
	info->node = i;
	if (i == 0 || i == 1)
		return ;
	flag = check_sorted(tmp);
	if (flag == 1)
		return ;
	if (i == 3)
	{
		a_node3(info);
		return ;
	}
	if (flag == -1)
	{
		reverse(info, i);
		return ;
	}
	else
		a2b(info, info->alist, info->blist, i);
}
