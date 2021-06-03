/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:00:31 by yubae             #+#    #+#             */
/*   Updated: 2021/06/03 19:34:48 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int main()
{
	t_node	*new;
	t_list	alist;
	t_list	blist;
	int		arr[7] = {1};

	new = 0;
	alist.head = new;

	for (int i = 0; i < 1 ; i++)
	{
		push(&alist, arr[i]);
	}
	
	display(&alist);
	push_swap(&alist);

	display(&alist);
}/*
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
	}*/
