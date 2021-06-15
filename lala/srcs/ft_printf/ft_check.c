/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:55:54 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 12:19:44 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->left = 0;
	info->zero = 0;
	info->width = 0;
	info->dot = -1;
	info->null = 0;
	info->type = 0;
}

int			check_w(const char *format, va_list ap, t_info *info, int i)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (format[i] == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->left = 1;
			info->zero = 0;
		}
		i++;
	}
	else if (ft_isdigit(format[i]) != 0)
	{
		start = i;
		while (ft_isdigit(format[i]) != 0)
			i++;
		end = i;
		info->width = ft_atoi_w(format, start, end);
	}
	return (i);
}

int			check_dot(const char *format, va_list ap, t_info *info, int i)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (format[i] == '*')
	{
		info->dot = va_arg(ap, int);
		i++;
	}
	else if (ft_isdigit(format[i]) != 0)
	{
		start = i;
		while (ft_isdigit(format[i]) != 0)
			i++;
		end = i;
		info->dot = ft_atoi_w(format, start, end);
	}
	return (i);
}

int			check_info(const char *format, va_list ap, t_info *info, int i)
{
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			info->left = 1;
		if (format[i] == '0')
			info->zero = 1;
		i++;
	}
	if (info->left == 1)
		info->zero = 0;
	i = check_w(format, ap, info, i);
	if (format[i] == '.')
	{
		info->dot = 0;
		i++;
		i = check_dot(format, ap, info, i);
	}
	return (i);
}
