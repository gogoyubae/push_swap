/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:09:01 by yubae             #+#    #+#             */
/*   Updated: 2021/06/28 14:10:15 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		sa(t_list *list)
{
	swap(list);
	ft_putstr("sa");
}

void		pa(t_list *from, t_list *to)
{
	int		num;
	t_node	*tmp;

	tmp = from->head;
	num = tmp->cont;
	pop(from);
	push(to, num);
	ft_putstr("pa");
}

void		ra(t_list *list)
{
	rotate(list);
	ft_putstr("ra");
}

void		rra(t_list *list)
{
	r_rotate(list);
	ft_putstr("rra");
}
