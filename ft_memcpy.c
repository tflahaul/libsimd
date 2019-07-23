/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:58:09 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/13 12:43:55 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <smmintrin.h>

void				ft_memcpy(void *dst, void *src, size_t len)
{
	unsigned char	*ptd;
	unsigned char	*pts;
	__m128i			*dstlongword;
	__m128i			*srclongword;

	dstlongword = (__m128i *)dst;
	srclongword = (__m128i *)src;
	while (len >= sizeof(__m128i))
	{
		_mm_storeu_si128(dstlongword++, _mm_loadu_si128(srclongword++));
		len = len - sizeof(__m128i);
	}
	ptd = (unsigned char *)dstlongword;
	pts = (unsigned char *)srclongword;
	while (len-- > 0)
		*ptd++ = *pts++;
}
