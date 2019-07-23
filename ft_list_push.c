/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:09:10 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:18:14 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsimd.h"

void				ft_list_push(t_listhead *node, t_listhead *head)
{
	ft_list_add(node, head, head->next);
}
