/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_less3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:21:12 by yubae             #+#    #+#             */
/*   Updated: 2021/06/18 16:48:13 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		max(t_info *info, t_list *list)
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

void		b_node2(t_info *info)
{
	int		node1;
	int		node2;
	t_list	*list;
	t_node	*tmp;

	list = info->blist;
	tmp = list->head;
	node1 = tmp->cont;
	tmp = tmp->next;
	node2 = tmp->cont;

	if (node1 > node2)
		sab(list);
	return ;
}

void		b_node3(t_info *info)
{
	min(info, info->blist);
	max(info, info->blist);
	if (info->max == 0 && info->min == 2)
		return ;
	else if (info->max == 0 && info->min == 1)
	{
		rrab(info->blist);
		sab(info->blist);
	}
	else if (info->max == 1 && info->min == 2)
		sab(info->blist);
	else if (info->max == 1 && info->min == 0)
		rab(info->blist);
	else if (info->max == 2 && info->min == 1)
		rrab(info->blist);
	else if (info->max == 2 && info->min == 0)
	{
		rab(info->blist);
		sab(info->blist);
	}
}

void		b_less3(t_info *info, int i)
{
	if (i <= 1)
		return ;
	if (i == 2)
		b_node2(info);
	else
		b_node3(info);
}
