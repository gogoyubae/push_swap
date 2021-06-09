/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:04:43 by yubae             #+#    #+#             */
/*   Updated: 2021/06/04 19:51:30 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	push_swap(t_info *info)
{
	int	i;
	t_list *tmp;

	tmp = info->alist;
	i = count_node(tmp);
	if (i <= 5)
		less5(info, i);
}

void	less5(t_info *info, int i)
{
	if (i == 0 || i == 1)
		return ;
	else if (i == 2)
		node2(info);
	else if (i == 3)
		node3(info);
/*	else if (i == 4)
		node_4(list);
	else if (i == 5)
		node_5(list);
*/	return ;
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
	int min;
	int	min_idx;

	min = info->min;
	min_idx = info->min_idx;

	if (min_idx == 0)
		pab(info->alist, info->blist);
	if (min_idx == 1)
	{
		sab(info->alist);
		pab(info->alist, info->blist);
		// swap 후 끝나는 경우 따져주기
	}
	if (min_idx == 2)
	{
		r_rotate(info->alist);
		pab(info->alist, info->blist);
	}
	node2(info);
	pab(info->blist, info->alist);
}

