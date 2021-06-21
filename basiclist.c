/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basiclist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:40:34 by yubae             #+#    #+#             */
/*   Updated: 2021/06/21 16:54:48 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		push(t_list *list, int n)
{
	t_node	*new;
	t_node	*tmp;

	new = new_node();
	new->cont = n;
	tmp = list->head;
	if (tmp == 0)
		list->head = new;
	else
	{
		new->next = tmp;
		tmp->prev = new;
		while (tmp->next != list->head)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		list->head = new;
	}	
}

void		rotate(t_list *list)
{
	t_node	*tmp;

	tmp = list->head;
	tmp = tmp->next;
	list->head = tmp;
}

void		r_rotate(t_list *list)
{
	t_node	*tmp;

	tmp = list->head;
	tmp = tmp->prev;
	list->head = tmp;
}


void		pop(t_list *list)
{
	t_node	*tmp;
	t_node	*head;
	t_node	*tail;

	tmp = list->head;
	if (tmp == 0)
		return ;
	if (tmp->next == tmp)
		list->head = 0;
	else
	{
		head = tmp->next;
		list->head = head;
		tail = head;
		while (tail->next != tmp)
			tail = tail->next;
		tail->next = head;
		head->prev = list->head;
	}
	free(tmp);
}


void		swap(t_list *list)
{
	int		*a;
	int		*b;
	int		num;
	t_node	*tmp;

	num = 0;
	tmp = list->head;
	if (tmp == 0 || tmp == tmp->next)
		return ;
	a = &tmp->cont;
	tmp = tmp->next;
	b = &tmp->cont;
	num = *a;
	*a = *b;
	*b = num;
}
