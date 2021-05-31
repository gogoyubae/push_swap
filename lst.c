/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:40:34 by yubae             #+#    #+#             */
/*   Updated: 2021/05/31 18:49:06 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_stack		*new_stack()
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->cont = 0;
	new->prev = new;
	new->next = new;
	return (new);
}
/*
t_stack		*new_stack()
{
	t_stack *head;
	t_stack *new;
	t_stack prev_tmp;
	t_stack next_tmp;

	head = malloc(sizeof(t_stack));
	new = malloc(sizeof(t_stack));
	if (!head || !new)
		return (0);
	head->cont = 0;
	new->cont = 0;
	head->prev = prev_tmp;
	head->next = next_tmp;
	head->prev = new->next;
	head->next = new->prev;
	new->cont = 0;
	new->prev = next_tmp;
	new->next = prev_tmp;
	return (new);
}
*/
void		push(t_stack **top, int n)
{
	t_stack *new;
	t_stack *tmp;

	new = new_stack();
	tmp = *top;
	new->cont = n;
	new->next = tmp;
	tmp->prev = new;
	while (tmp->next != *top)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

void		pop(t_stack **top)
{
	t_stack *head;
	t_stack *tail;
	t_stack *tmp;

	tmp = *top;
	head = tmp->next;
	tail = tmp;
	while (tail->next != tmp)
		tail = tail->next;
	head->prev = tail;
	tail->next = head;
	free(*top);
}
/*
void		*del_stack(t_stack *s)
{
	t_list	tmp;
	s->next = tmp;
	s->next = s->prev;
	s->prev = tmp;
	free(s);
}
*/
void display(t_stack *s)
{
	t_stack *tmp;

	tmp = s->next;
	printf("start >");
	while(tmp != s)
	{
		printf(" %d ", tmp->cont);
		tmp = tmp->next;
	}
}
int main()
{
	t_stack *a;

	a = new_stack();
	push(&a, 202);
	push(&a, 102);
	push(&a, 12);
	push(&a, 2202);
	display(a);
}
