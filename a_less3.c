/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_less3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:21:12 by yubae             #+#    #+#             */
/*   Updated: 2021/06/25 18:37:36 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		min(t_info *info, t_list *list)
{
	int		idx;
	int		j;
	int		min;
	t_node	*tmp;

	idx = 0;
	j = 1;
	tmp = list->head;
	min = tmp->cont;
	while (j < 3)
	{
		tmp = tmp->next;
		if (min > tmp->cont)
		{
			min = tmp->cont;
			idx = j;
		}
		j++;
	}
	info->min = idx;
}

//void		min(t_info *info, t_list *list)
//{
//	int		i;
//	int		min;
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
//		printf("%d", arr[i]);
//	}
//	i = 0;
//	min = arr[0];
//	while (i < 3)
//	{
//		if (min > arr[i])
//		{
//			min = arr[i];
//			idx = i;
//		}
//	}
//	info->min = idx;
//	printf("min: %d",i);
//}

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

//void		a_node3(t_info *info)
//{
//	min(info, info->alist);
//	max(info, info->alist);
//	printf("min %d, max %d", info->min, info->max);
//	if (info->min == 0 && info->max == 2)
//		return ;
//	else if (info->min == 0 && info->max == 1)
//	{
//		ra(info->alist);
//		sa(info->alist);
//		rra(info->alist);
//	}
//	else if (info->min == 1 && info->max == 2)
//		sa(info->alist);
//	else if (info->min == 1 && info->max == 0)
//	{
//		sa(info->alist);
//		ra(info->alist);
//		sa(info->alist);
//		rra(info->alist);
//	}
//	else if (info->min == 2 && info->max == 1)
//	{
//		ra(info->alist);
//		sa(info->alist);
//		rra(info->alist);
//		sa(info->alist);
//	}
//	else if (info->min == 2 && info->max == 0)
//	{
//		ra(info->alist);
//		sa(info->alist);
//	}
//}

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
	else if (i == 3 && info->node <= 5)
		a_node3(info);
}
