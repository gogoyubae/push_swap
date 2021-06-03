/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:04:43 by yubae             #+#    #+#             */
/*   Updated: 2021/06/03 19:32:41 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	push_swap(t_list *list)
{
	int	i;

	i = count_node(list);
	if (i <= 5)
		less5(list, i);
}

void	less5(t_list *list, int i)
{
	if (i == 0 || i == 1)
		return ;
	else if (i == 2)
		node_2(list);
/*	else if (i == 3)
		node_3(list);
	else if (i == 4)
		node_4(list);
	else if (i == 5)
		node_5(list);
*/	return ;
}

void		node_2(t_list *list)
{
	int		node1;
	int		node2;
	t_node *tmp;

	tmp = list->head;
	node1 = tmp->cont;
	tmp = tmp->next;
	node2 = tmp->cont;

	if (node1 > node2)
		sab(list);
	return ;
}
