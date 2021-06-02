/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubae <yubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:13:46 by yubae             #+#    #+#             */
/*   Updated: 2021/06/02 18:56:39 by yubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
#define LST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_node
{
	struct s_node	*prev;
	int				cont;
	struct s_node	*next;
}t_node;

typedef struct		s_list
{
	t_node			*head;
}t_list;

#endif
