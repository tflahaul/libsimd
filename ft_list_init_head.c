/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:05:19 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:18:28 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsimd.h"

void				ft_list_init_head(t_listhead *head)
{
	head->next = head;
	head->prev = head;
}
