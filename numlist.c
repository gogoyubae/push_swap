/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:55:44 by yubae             #+#    #+#             */
/*   Updated: 2021/06/24 15:08:52 by yubae            ###   ########.fr       */
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
	while (i < len)
	{
		if (!me_isdigit(num[i]))
			return (0);
		i++;
	}
	if (len > 10)
		return (0);
	res = ft_atolli(num);
	if (-2147483648 > res || 2147483647 < res)
		return (0);
	return (1);
}

int			samenum(int argc, int *arr)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			*copylist(int argc, char *argv[])
{
	int		i;
	int		*arr;
	char	*num;

	i = 1;
	if (!(arr = malloc(sizeof(int[argc - 1]))))
		return (0);
	while (i < argc)
	{
		num = argv[i];
		if (!checkint(num))
			return (0);
		arr[i - 1] = ft_atoi(num);
		i++;
	}
	if (!samenum(argc, arr))
		return (0);
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
