/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:41:27 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/13 12:13:33 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <smmintrin.h>

void				ft_bzero(void *ptr, size_t size)
{
	unsigned char	*mem;
	__m128i			*longword;
	__m128i const	set = _mm_setzero_si128();

	longword = (__m128i *)ptr;
	while (size >= sizeof(__m128i))
	{
		_mm_storeu_si128(longword++, set);
		size = size - sizeof(__m128i);
	}
	mem = (unsigned char *)longword;
	while (size-- > 0)
		*mem++ = 0;
}
