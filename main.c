/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:55:17 by yubae             #+#    #+#             */
/*   Updated: 2021/06/21 17:16:22 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int			main(int argc, char *argv[])
{
	t_node	*new;
	t_list	a;
	t_list	b;
	t_info	info;
	int		*arr;

	new = 0;
	a.head = 0;
	b.head = 0;
	info.alist = &a;
	info.blist = &b;
	if (argc < 2)
		return (0);
	arr = copylist(argc, argv);
	if (arr == 0)
	{
		ft_putstr("Error");
		return (0);
	}
	initlist(&a, argc, arr);
	push_swap(&info);
	free(arr);
}
