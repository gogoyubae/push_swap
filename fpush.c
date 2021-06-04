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
	t_list tmp;

	tmp = info->alist;
	i = count_node(&tmp);
	display(&tmp);
	if (i <= 5)
		less5(info, i);
}

void	less5(t_info *info, int i)
{
	if (i == 0 || i == 1)
		return ;
	else if (i == 2)
		node_2(info);
//	else if (i == 3)
//		node_3(info);
/*	else if (i == 4)
		node_4(list);
	else if (i == 5)
		node_5(list);
*/	return ;
}

void		node_2(t_info *info)
{
	int		node1;
	int		node2;
	t_list	*list;
	t_node	*tmp;

	list = &info->alist;
	tmp = list->head;
	node1 = tmp->cont;
	tmp = tmp->next;
	node2 = tmp->cont;

	if (node1 > node2)
		sab(list);
	return ;
}
/*
void		node_3(t_info *info)
{
	int min;

	min = info->*/
