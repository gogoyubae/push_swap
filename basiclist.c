/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basiclist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:40:34 by yubae             #+#    #+#             */
/*   Updated: 2021/06/03 17:15:01 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_node		*new_node()
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->cont = 0;
	new->prev = new;
	new->next = new;
	return (new);
}

void		push(t_list *list, int n)
{
	t_node *new;
	t_node *tmp;

	new = new_node();
	new->cont = n;
	tmp = list->head;
	if (tmp == 0)
	{
		list->head = new;
		return ;
	}
	new->next = tmp;
	tmp->prev = new;
	while (tmp->next != list->head)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
	list->head = new;
}

void		rotate(t_list *list)
{
	t_node *tmp;

	tmp = list->head;
	tmp = tmp->next;
	list->head = tmp;
}

void		r_rotate(t_list *list)
{
	t_node *tmp;

	tmp = list->head;
	tmp = tmp->prev;
	list->head = tmp;
}


void		pop(t_list *list)
{
	t_node *tmp;
	t_node *head;
	t_node *tail;

	tmp = list->head;
	if (tmp == 0)
	{
		printf("no ele");
		return ;
	}
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

int		count_node(t_list *list)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = list->head;
	if (tmp != 0)
	{
		i++;
		tmp = tmp->next;
		while (tmp != list->head)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

void		display(t_list *list)
{
	t_node *tmp;

	
	if (list->head == 0)
	{
		printf("nono\n");
		return ;
	}
	tmp = list->head;
	printf("start >");
	printf("cont:%d ", tmp->cont);
	tmp = tmp->next;
	while (tmp !=  list->head)
	{
		printf(" cont:%d ", tmp->cont);
		tmp = tmp->next;
	}
	printf("< end\n ");
	int i = count_node(list);
	printf("node: %d\n", i);
}
int main()
{
	t_node	*new;
	t_list	alist;
	t_list	blist;
/*	int		arr[7] = {7, 6, 5, 4, 3, 2, 1};

	new = 0;
	list.head = new;

	for (int i = 0; i < 7; i++)
	{
		push(&alist, arr[i]);
	}
	display(&alist);
}*/
	new = 0;
	alist.head = new;
	blist.head = new;
	sab(&alist);
	display(&alist);
	push(&alist, 1);
	sab(&alist);
	display(&alist);
	push(&alist, 2);
	display(&alist);
	sab(&alist);
	display(&alist);
	pab(&alist, &blist);
	printf("alist");
	display(&alist);
	printf("blist");
	display(&blist);
	}
	/*
	push(&list, 2);
	display(&list);
	push(&list, 3);
	push(&list, 4);
	display(&list);
	swap(&list);
	display(&list);
	rotate(&list);
	printf("한 칸 올림");
	display(&list);
	r_rotate(&list);

	printf("한 칸 내림");
	display(&list);

	pop(&list);
	display(&list);
	pop(&list);
	display(&list);
	pop(&list);
	display(&list);
	pop(&list);
	display(&list);*/

