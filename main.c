/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:00:31 by yubae             #+#    #+#             */
/*   Updated: 2021/06/04 19:42:47 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int main()
{
	t_node	*new;
	t_list	a;
	t_list	b;
	t_info	info;
	int		arr[2] = {1, 3};

	new = 0;
	a.head = new;
	info.alist = a;
	info.min = arr[0];

	for (int i = 0; i < 2 ; i++)
	{
		push(&a, arr[i]);
		if (info.min >arr[i])
			info.min = arr[i];
	}
	
	display(&a);
	push_swap(&info);

	display(&a);
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
