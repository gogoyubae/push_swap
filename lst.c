/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:40:34 by yubae             #+#    #+#             */
/*   Updated: 2021/05/20 20:34:35 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_stack		*new_stack(int n)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->cont = n;
	new->prev = 0;
	new->next = 0;
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

	new = new_stack(n);
	tmp = *top;
	if (!new)
		return (0);
	new->next = top;
	top->prev = new;
	while(tmp->next != top)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
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
int main()
{
	t_stack *a;
	t_stack *b;
	a = new_stack(20);
	b = new_stack(30);
	a->prev = b;
	b->prev = a;
	a->next = b;
	b->next = a;
	push(&a, 10);
	t_stack tmp;
	tmp = a;
	while(tmp->next != a)
	{
		printf("%d", tmp->cont);
		tmp = tmp->next;
	}
}
