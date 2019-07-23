/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:03:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:18:21 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libsimd.h"

void				ft_list_pop(t_listhead *node, void *(ptr)(t_listhead *))
{
	node->next->prev = node->prev;
	node->prev->next = node->next;
	node->next = __DARWIN_NULL;
	node->prev = __DARWIN_NULL;
	free((*ptr)(node));
}
