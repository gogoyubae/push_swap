/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:07:29 by yubae             #+#    #+#             */
/*   Updated: 2021/06/28 13:29:02 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		sb(t_list *list)
{
	swap(list);
	ft_putstr("sb");
}

void		pb(t_list *from, t_list *to)
{
	int		num;
	t_node	*tmp;

	tmp = from->head;
	num = tmp->cont;
	pop(from);
	push(to, num);
	ft_putstr("pb");
}

void		rb(t_list *list)
{
	rotate(list);
	ft_putstr("rb");
}

void		rrb(t_list *list)
{
	r_rotate(list);
	ft_putstr("rrb");
}
