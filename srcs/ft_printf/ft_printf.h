/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:57:15 by yubae             #+#    #+#             */
/*   Updated: 2021/04/05 10:53:10 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# define TYPE "csdiupxX%"
# define FLAG "-.0123456789"

typedef struct	s_info
{
	int			left;
	int			zero;
	int			width;
	int			dot;
	int			null;
	int			type;
}				t_info;

int				ft_printf(const char *format, ...);
void			init_info(t_info *info);
int				check_w(const char *format, va_list ap, t_info *info, int i);
int				check_dot(const char *format, va_list ap, t_info *info, int i);
int				check_info(const char *format, va_list ap, t_info *info, int i);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				num_space(t_info *info, long long n, int space);
int				num_width(t_info *info, long long n, int space, char *num);
char			*prec_null(t_info *info, long long n, char *num);
char			*join_zero(t_info *info, long long n, char *num, int len);
int				ft_putdi(t_info *info, long long n);
int				ft_putux(t_info *info, unsigned int n);
char			*ft_x(long long n);
int				tmp_space(t_info *info, int space);
int				ft_putp(t_info *info, long long n);
int				ft_putpct(t_info *info);
int				ft_putc(t_info *info, int c);
int				ft_puts(t_info *info, char *s);
int				ft_atoi_w(const char *format, int start, int end);
#endif
