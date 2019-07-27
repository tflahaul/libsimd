/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:07:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:20:02 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsimd.h"

__inline void		ft_list_add(t_listhead *node, t_listhead *prev, t_listhead *next)
{
	next->prev = node;
	node->next = next;
	node->prev = prev;
	prev->next = node;
}
