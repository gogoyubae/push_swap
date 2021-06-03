/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:45:02 by yubae             #+#    #+#             */
/*   Updated: 2021/06/03 19:34:12 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	sab(t_list *list)
{
	swap(list);
	printf("swap\n");
}

void	pab(t_list *from, t_list *to)
{
	int		num;
	t_node *tmp;

	tmp = from->head;
	num = tmp->cont;
	pop(from);
	push(to, num);
	printf("pushpop\n");
}

void	rab(t_list *list)
{
		rotate(list);
		printf("rotate\n");
}

void	rrab(t_list *list)
{
		r_rotate(list);
		printf("reverse rotate\n");
}
