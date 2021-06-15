/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:56:42 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 19:51:50 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_format(va_list ap, t_info *info)
{
	int		res;

	res = 0;
	if (info->type == '%')
		res = ft_putpct(info);
	if (info->type == 'c')
		res = ft_putc(info, va_arg(ap, int));
	if (info->type == 's')
		res = ft_puts(info, va_arg(ap, char *));
	if (info->type == 'd' || info->type == 'i')
		res = ft_putdi(info, va_arg(ap, int));
	if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		res = ft_putux(info, va_arg(ap, unsigned int));
	if (info->type == 'p')
		res = ft_putp(info, va_arg(ap, long long));
	return (res);
}

int			check_format(const char *format, va_list ap)
{
	int		i;
	int		res;
	t_info	*info;

	i = 0;
	res = 0;
	while (format[i] != 0)
	{
		while (format[i] != '%' && format[i] != 0)
			res += ft_putchar(format[i++]);
		if (format[i] == '%' && format[++i] != 0)
		{
			if (!(info = malloc(sizeof(t_info))))
				return (-1);
			init_info(info);
			if (ft_strchr(TYPE, format[i]) == 0 && format[i] != 0)
				i = check_info(format, ap, info, i);
			info->type = format[i++];
			if (info->type == 0)
				return (-1);
			res += print_format(ap, info);
			free(info);
		}
	}
	return (res);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret_size;

	ret_size = 0;
	va_start(ap, format);
	ret_size = check_format(format, ap);
	va_end(ap);
	if (ret_size == -1)
		return (-1);
	return (ret_size);
}
