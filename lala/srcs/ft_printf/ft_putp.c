/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:46:03 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 11:51:27 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*prec_null_p(t_info *info, long long n, char *num)
{
	if (info->dot == 0 && n == 0)
	{
		free(num);
		if (!(num = ft_strdup("0x")))
			return (0);
	}
	return (num);
}

char		*join_zero_p(t_info *info, long long n, char *num, int len)
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
		num = prec_null_p(info, n, num);
		if (!num || !(prec = ft_strdup("")))
			return (0);
	}
	res = ft_strjoin(prec, num);
	free(prec);
	free(num);
	return (res);
}

int			ft_putp(t_info *info, long long n)
{
	char	*num;
	char	*tmp;
	int		len;
	int		space;
	int		res;

	if (!(tmp = ft_x(n)))
		return (-1);
	if (!(num = ft_strjoin("0x", tmp)))
		return (-1);
	free(tmp);
	if (info->dot >= 0)
	{
		len = ft_strlen(num);
		if (!(num = join_zero_p(info, n, num, len)))
			return (-1);
		info->zero = 0;
	}
	len = ft_strlen(num);
	space = info->width - len;
	res = num_width(info, n, space, num);
	free(num);
	return (res);
}
