/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:40:34 by yubae             #+#    #+#             */
/*   Updated: 2021/06/01 20:10:18 by yubae            ###   ########.fr       */
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

void		swap(t_stack **top)
{
	int		*a;
	int		*b;
	int		*num;
	t_stack	*tmp;

	tmp = *top;
	*a = tmp->cont;
	tmp = tmp->next;
	*b = tmp->cont;

	*num = *a;
	*a = *b;
	*b = *num;
}

void		display(t_stack *s)
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
	swap(&a);
	display(a);
}
