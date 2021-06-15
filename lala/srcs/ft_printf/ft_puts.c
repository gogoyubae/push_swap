/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:00:50 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 11:53:22 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			tmp_space(t_info *info, int space)
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
	return (i);
}

int			s_width(t_info *info, int space, char *tmp)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (space < 0 || info->left == 1)
	{
		res += ft_putstr(tmp);
		if (space > 0)
			res += tmp_space(info, space);
	}
	else
	{
		tmp_space(info, space);
		ft_putstr(tmp);
		res = info->width;
	}
	return (res);
}

char		*prec_s(t_info *info, char *tmp)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(tmp);
	if (info->dot < len)
	{
		if (!(res = malloc(sizeof(char) * (info->dot + 1))))
			return (0);
		while (i < info->dot)
		{
			res[i] = tmp[i];
			i++;
		}
		res[i] = 0;
		free(tmp);
	}
	else
		res = tmp;
	return (res);
}

int			ft_puts(t_info *info, char *s)
{
	char	*tmp;
	int		len;
	int		space;
	int		res;

	if (s == 0)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(s);
	if (!tmp)
		return (-1);
	if (info->dot >= 0)
	{
		if (!(tmp = prec_s(info, tmp)))
			return (-1);
		info->zero = 0;
	}
	len = ft_strlen(tmp);
	space = info->width - len;
	res = s_width(info, space, tmp);
	free(tmp);
	return (res);
}
