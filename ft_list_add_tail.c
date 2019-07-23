/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_tail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:09:34 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:18:48 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsimd.h"

void				ft_list_add_tail(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head->prev, head);
}
