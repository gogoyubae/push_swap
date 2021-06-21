/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:50:48 by yubae             #+#    #+#             */
/*   Updated: 2021/06/21 15:51:37 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

size_t				ft_strlen(const char *str)
{
	size_t			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void				ft_putstr(char *str)
{
	size_t			i;
	size_t			len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

long long int		ft_atolli(const char *str)
{
	int				i;
	int				flag;
	long long int	res;

	i = 0;
	flag = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * flag);
}

int					ft_atoi(const char *str)
{
	int				i;
	int				flag;
	int				res;

	i = 0;
	flag = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * flag);
}
