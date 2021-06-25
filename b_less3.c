/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_less3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:21:12 by yubae             #+#    #+#             */
/*   Updated: 2021/06/25 18:37:43 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		max(t_info *info, t_list *list)
{
	int		idx;
	int		j;
	int		max;
	t_node	*tmp;

	idx = 0;
	j = 1;
	tmp = list->head;
	max = tmp->cont;
	while (j < 3)
	{
		tmp = tmp->next;
		if (max < tmp->cont)
		{
			max = tmp->cont;
			idx = j;
		}
		j++;	
	}
	info->max = idx;
}

//void		max(t_info *info, t_list *list)
//{
//	int		i;
//	int		max;
//	int		idx;
//	int		arr[3];
//	t_node	*tmp;
//
//	i = 0;
//	tmp = list->head;
//	while (i++ < 3)
//	{
//		arr[i] = tmp->cont;
//		tmp = tmp->next;
//	}
//	i = 0;
//	max = arr[i];
//	while (i++ < 3)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//			idx = i;
//		}
//	}
//	info->max = idx;
//	printf("min: %d",i);
//}

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
	if (node1 < node2)
		sb(list);
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
		rrb(info->blist);
		sb(info->blist);
	}
	else if (info->max == 1 && info->min == 2)
		sb(info->blist);
	else if (info->max == 1 && info->min == 0)
		rb(info->blist);
	else if (info->max == 2 && info->min == 1)
		rrb(info->blist);
	else if (info->max == 2 && info->min == 0)
	{
		rb(info->blist);
		sb(info->blist);
	}
}

void		b_less3(t_info *info, int i)
{
	if (i == 2)
		b_node2(info);
	else if (i == 3 && info->node <= 5)
		b_node3(info);
	while (i-- > 0)
		pa(info->blist, info->alist);
}
