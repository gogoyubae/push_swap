/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:40:34 by yubae             #+#    #+#             */
/*   Updated: 2021/06/02 16:06:02 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list		*new_list()
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->head = 0;
	return (new);
}

void		push(t_list **top, int n)
{
	t_list *new;
	t_list *tmp;

	new = new_list();
	tmp = *top;
	new->cont = n;
	new->next = tmp;
	tmp->prev = new;
	while (tmp->next != *top)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

void		pop(t_list **top)
{
	t_list *head;
	t_list *tail;
	t_list *tmp;

	tmp = *top;
	head = tmp->next;
	tail = tmp;
	while (tail->next != tmp)
		tail = tail->next;
	head->prev = tail;
	tail->next = head;
	free(*top);
}

void		swap(t_head *h)
{/*
	int		*a;
	int		*b;
	int		*num;
	t_list	*tmp;

	tmp = *top;
	*a = tmp->cont;
	tmp = tmp->next;
	*b = tmp->cont;

	*num = *a;
	*a = *b;
	*b = *num;
*/
	t_list *top;
	int		a;
	int		b;
	int		tmp;


	top = h->head;
	top->cont = a;
	tmp = a;
	top = top->next;
	top->cont = b;



}

void		display(t_list *s)
{
	t_list *tmp;

	tmp = s->next;
	printf("start >");
	while(tmp != s)
	{
		printf(" cont:%d ", tmp->cont);
		tmp = tmp->next;
	}
}
int main()
{
	t_list	*a;
	t_head	*h;

	a = new_list();
	h->head = a;	
	push(&a, 202);
	push(&a, 102);
	push(&a, 12);
	push(&a, 2202);
	display(a);
	//swap(h);
	//display(a);
}
