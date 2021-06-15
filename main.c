/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:00:31 by yubae             #+#    #+#             */
/*   Updated: 2021/06/15 20:31:06 by yubae            ###   ########.fr       */
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
	i = 2;
	printf("argc - i: %d\n", arr[4]);
	while (i <= argc)
	{
		printf("%d\n", arr[4]);
		push(&a, arr[argc - i]);
		i++;
	}for (int k = 0; k < argc - 1; k++)
		printf("arr[%d]:%d ", k, arr[k]);
	printf("\n");
	display(&a);
	push_swap(&info);
	display(&a);
	free(arr);
}

/*
int			main(int argc, char *argv[])
{
	t_node	*new;
	t_list	a;
	t_list	b;
	t_info	info;
	int		*arr;
	int		*quick;
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
	quick = arr;
	quicksort(quick, 0, 4);
	for (int i = 0; i <5; i++)
	{
		printf("qsarr[%d]: %d ", i, quick[i]);
	}
	info.min = quick[0];
	info.min_idx = 0;
	info.max = quick[4];
	info.max_idx = 4;
	printf("min: %d, min idx: %d",info.min, info.min_idx);
	push_swap(&info);

	display(&a);
	free(arr);
}

					
*/

