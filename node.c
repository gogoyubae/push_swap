/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:40:34 by yubae             #+#    #+#             */
/*   Updated: 2021/06/21 16:55:21 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_node		*new_node(void)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->cont = 0;
	new->prev = new;
	new->next = new;
	return (new);
}

int			count_node(t_list *list)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = list->head;
	if (tmp != 0)
	{
		i++;
		tmp = tmp->next;
		while (tmp != list->head)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
