/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:52:54 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 12:01:09 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			x_len(long long n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char		*ft_x(long long n)
{
	char	*p;
	char	*base;
	int		i;
	int		len;

	base = "0123456789abcdef";
	i = 0;
	len = x_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (n > 0)
	{
		p[len - i - 1] = base[n % 16];
		n /= 16;
		i++;
	}
	p[len] = '\0';
	return (p);
}

char		*ft_xx(long long n)
{
	char	*p;
	char	*base;
	int		i;
	int		len;

	base = "0123456789ABCDEF";
	i = 0;
	len = x_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (n > 0)
	{
		p[len - i - 1] = base[n % 16];
		n /= 16;
		i++;
	}
	p[len] = '\0';
	return (p);
}

char		*ft_base(t_info *info, unsigned int n)
{
	char *num;

	if (info->type == 'u')
		num = ft_itoa(n);
	if (info->type == 'x')
		num = ft_x(n);
	if (info->type == 'X')
		num = ft_xx(n);
	return (num);
}

int			ft_putux(t_info *info, unsigned int n)
{
	char	*num;
	int		len;
	int		space;
	int		res;

	num = ft_base(info, n);
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
