/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 00:43:01 by yubae             #+#    #+#             */
/*   Updated: 2021/01/10 15:07:41 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new_lst;

	if (!(new_lst = malloc(sizeof(t_list))))
		return (0);
	new_lst->content = content;
	new_lst->next = 0;
	return (new_lst);
}
