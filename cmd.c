/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:45:02 by yubae             #+#    #+#             */
/*   Updated: 2021/06/03 17:14:13 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	sab(t_list *list)
{
	swap(list);
}

void	pab(t_list *from, t_list *to)
{
	int		num;
	t_node *tmp;

	tmp = from->head;
	num = tmp->cont;
	pop(from);
	push(to, num);
}

void	rab(t_list *list)
{

}

void	rrab(t_list *list)
{

}
