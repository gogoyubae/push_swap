/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:01:10 by yubae             #+#    #+#             */
/*   Updated: 2021/04/03 16:01:23 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	if (!c)
		write(1, "\x00", 1);
	else
		write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = ft_strlen(s);
	while (i < strlen)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (strlen);
}

int		ft_atoi_w(const char *format, int start, int end)
{
	int	width;

	width = 0;
	while (start < end)
	{
		width = width * 10 + (format[start] - '0');
		start++;
	}
	return (width);
}
