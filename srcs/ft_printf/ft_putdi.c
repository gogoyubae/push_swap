/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:57:51 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 11:25:15 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			num_space(t_info *info, long long n, int space)
{
	int		i;

	i = 0;
	while (i < space)
	{
		if (info->zero == 0)
			i += ft_putchar(' ');
		else if (info->left == 0)
			i += ft_putchar('0');
	}
	if (n < 0 && info->left == 0 && info->zero == 0)
		ft_putchar('-');
	return (i);
}

int			num_width(t_info *info, long long n, int space, char *num)
{
	int		res;

	res = 0;
	if (space < 0 || info->left == 1)
	{
		if (n < 0)
			res += ft_putchar('-');
		res += ft_putstr(num);
		if (space > 0)
			res += num_space(info, n, space);
	}
	else
	{
		if (n < 0 && info->zero == 1)
			ft_putchar('-');
		num_space(info, n, space);
		ft_putstr(num);
		res = info->width;
	}
	return (res);
}

char		*prec_null(t_info *info, long long n, char *num)
{
	if (info->dot == 0 && n == 0)
	{
		free(num);
		if (!(num = ft_strdup("")))
			return (0);
	}
	return (num);
}

char		*join_zero(t_info *info, long long n, char *num, int len)
{
	int		i;
	int		zero;
	char	*prec;
	char	*res;

	i = 0;
	zero = info->dot - len;
	if (zero > 0)
	{
		if (!(prec = malloc(sizeof(zero + 1))))
			return (0);
		while (i < zero)
			prec[i++] = '0';
		prec[i] = 0;
	}
	else
	{
		num = prec_null(info, n, num);
		if (!(num && (prec = ft_strdup(""))))
			return (0);
	}
	res = ft_strjoin(prec, num);
	free(prec);
	free(num);
	return (res);
}

int			ft_putdi(t_info *info, long long n)
{
	char	*num;
	int		len;
	int		space;
	int		res;

	if (n < 0)
		num = ft_itoa(-n);
	else
		num = ft_itoa(n);
	if (!num)
		return (-1);
	if (info->dot >= 0)
	{
		len = ft_strlen(num);
		if (!(num = join_zero(info, n, num, len)))
			return (-1);
		info->zero = 0;
	}
	len = ft_strlen(num);
	space = info->width - len;
	if (n < 0)
		space--;
	res = num_width(info, n, space, num);
	free(num);
	return (res);
}
