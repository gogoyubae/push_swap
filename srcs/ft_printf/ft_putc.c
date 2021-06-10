/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:37:58 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 11:09:38 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			c_width(t_info *info, int space, int c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (space < 0 || info->left == 1)
	{
		if (info->null == 1)
			res += ft_putchar(0);
		else
			res += ft_putchar(c);
		if (space > 0)
			res += tmp_space(info, space);
	}
	else
	{
		tmp_space(info, space);
		if (info->null == 1)
			ft_putchar(0);
		else
			ft_putchar(c);
		res = info->width;
	}
	return (res);
}

int			ft_putpct(t_info *info)
{
	char	*tmp;
	int		n;
	int		space;
	int		res;

	n = 0;
	if (!(tmp = ft_strdup("%")))
		return (-1);
	if (info->dot >= 0)
		info->dot = -1;
	space = info->width - 1;
	res = num_width(info, n, space, tmp);
	free(tmp);
	return (res);
}

int			ft_putc(t_info *info, int c)
{
	int		space;
	int		res;

	if (c == 0)
		info->null = 1;
	if (info->dot >= 0)
		info->dot = -1;
	space = info->width - 1;
	res = c_width(info, space, c);
	return (res);
}
