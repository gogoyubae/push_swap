/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:00:31 by yubae             #+#    #+#             */
/*   Updated: 2021/06/09 20:27:47 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int main()
{
	t_node	*new;
	t_list	a;
	t_list	b;
	t_info	info;
	int		arr[5] = {5, 4, 3, 2, 1};

	new = 0;
	a.head = new;
	b.head = new;
	info.alist = &a;
	info.blist = &b;
	info.min = arr[0];
	info.max = arr[0];

	for (int i = 4; i >= 0 ; i--)
	{
		push(&a, arr[i]);
		if (info.min > arr[i])
		{
			info.min = arr[i];
			info.min_idx = i;
		}
		if (info.max < arr[i])
		{
			info.max = arr[i];
			info.max_idx = i;
		}
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
