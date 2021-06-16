/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:00:31 by yubae             #+#    #+#             */
/*   Updated: 2021/06/16 16:05:45 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int						me_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int						checkint(char *num)
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
	if (-2147483648 > res || 2147483647 < res)
		return (0);
	return (1);
}

int			*copylist(int argc, char *argv[])
{
	int		i;
	int		*arr;
	char	*num;

	i = 1;
	if (argc < 2)
		return (0);
	arr = malloc(sizeof(int[argc - 1]));
	if (!arr)
		return (0);
	while (i < argc)
	{
		num = argv[i];
		if (!checkint(num))
			return (0);
		arr[i - 1] = ft_atoi(num);
		i++;
	}
	return (arr);
}

void		initlist(t_list *list, int argc, int *arr)
{
	int		i;

	i = 2;
	while (i <= argc)
	{
		push(list, arr[argc - i]);
		i++;
	}
}
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
	arr = copylist(argc, argv);
	if (arr == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	initlist(&a, argc, arr);
	for (int k = 0; k < 5; k++)
		printf("arr %d ", arr[k]);
	/*
	i = 2;
	while (i <= argc)
	{
		push(&a, arr[argc - i]);
		i++;
	}*/

	printf("\n");
	display(&a);
	push_swap(&info);
	display(&a);
	free(arr);
}

