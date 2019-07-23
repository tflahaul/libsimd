/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:43:49 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/16 13:55:04 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <smmintrin.h>

void					*ft_memset(void *dst, int c, size_t size)
{
	unsigned char		*ptr;
	__m128i				*longword;
	__m128i const		set = _mm_set1_epi8(c);

	longword = (__m128i *)dst;
	while (size >= sizeof(__m128i))
	{
		_mm_storeu_si128(longword++, set);
		size = size - sizeof(__m128i);
	}
	ptr = (unsigned char *)longword;
	while (size-- > 0)
		*ptr++ = c;
	return (dst);
}
