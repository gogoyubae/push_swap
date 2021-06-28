/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:50:39 by yubae             #+#    #+#             */
/*   Updated: 2021/06/28 13:31:28 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		display(t_list *list)
{
	t_node	*tmp;

	if (list->head == 0)
	{
		printf("nono\n");
		return ;
	}
	tmp = list->head;
	printf("start >");
	printf("cont:%d ", tmp->cont);
	tmp = tmp->next;
	while (tmp != list->head)
	{
		printf(" cont:%d ", tmp->cont);
		tmp = tmp->next;
	}
	printf("< end\n");
}
