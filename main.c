/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:00:31 by yubae             #+#    #+#             */
/*   Updated: 2021/06/10 20:03:38 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int			me_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			checkint(char *num)
{
	int					i;
	int					len;
	long long int		res;

	i = 0;
	len = 0;
	if (num[i] == '-' && !me_isdigit(num[i + 1]))
		return (0);
	if (num[i] == '-')
		i++;
	len = ft_strlen(&num[i]);
	if (len > 10)
		return (0);
	res = ft_atolli(num);
	if (-2147483648 > res || 2147483648 < res)
		return (0);
	return (res);
}

int			*copylist(int argc, char *argv[])
{
	int		i;
	int		*arr;
	char	*num;

	i = 1;
	if (argc < 2)
		return (0);
	arr = malloc(sizeof(arr[argc - 1]));
	if (!arr)
		return (0);
	while (i < argc)
	{
		num = argv[i];
		if (!checkint(num))
			return (0);
		arr[i - 1] = checkint(num);
		i++;
	}
	return (arr);
}



int			main(int argc, char *argv[])
{
	t_node	*new;
	t_list	a;
	t_list	b;
	t_info	info;
	int		*arr;
	int		i;

	new = 0;
	a.head = new;
	b.head = new;
	info.alist = &a;
	info.blist = &b;
	arr = copylist(argc, argv);
	if (arr == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	info.min = arr[0];
	info.max = arr[0];
	i = argc - 2;
	while (i >= 0)
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
		i--;
	}
	display(&a);
	push_swap(&info);

	display(&a);
	free(arr);
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
