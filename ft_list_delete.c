/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:37:07 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:18:35 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libsimd.h"

void			ft_list_delete(t_listhead *head, void *(*funptr)(t_listhead *))
{
	t_listhead	*node;
	t_listhead	*next;

	node = head->next;
	next = node->next;
	while (node != head)
	{
		free((*funptr)(node));
		node = next;
		next = node->next;
	}
}
