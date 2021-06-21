/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_less3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:21:12 by yubae             #+#    #+#             */
/*   Updated: 2021/06/21 15:44:26 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		min(t_info *info, t_list *list)
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

void		a_node2(t_info *info)
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
		sa(list);
	return ;
}

void		a_node3(t_info *info)
{
	min(info, info->alist);
	max(info, info->alist);
	if (info->min == 0 && info->max == 2)
		return ;
	else if (info->min == 0 && info->max == 1)
	{
		rra(info->alist);
		sa(info->alist);
	}
	else if (info->min == 1 && info->max == 2)
		sa(info->alist);
	else if (info->min == 1 && info->max == 0)
		ra(info->alist);
	else if (info->min == 2 && info->max == 1)
		rra(info->alist);
	else if (info->min == 2 && info->max == 0)
	{
		ra(info->alist);
		sa(info->alist);
	}
}

void		a_less3(t_info *info, int i)
{
	if (i <= 1)
		return ;
	if (i == 2)
		a_node2(info);
	else
		a_node3(info);
}
