/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:23:54 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/28 11:46:42 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <smmintrin.h>
#include "libsimd.h"

#define FLAG		(_SIDD_SBYTE_OPS | _SIDD_MOST_SIGNIFICANT)

char				*ft_strrchr(char const *str, int c)
{
	char			*ptr;
	__m128i			chunk;
	__m128i			*longword;
	__m128i const	set = _mm_setr_epi16(c, 0, 0, 0, 0, 0, 0, 0);

	ptr = NULL;
	if (__unlikely(!__isaligned(str, sizeof(__m128i)))) {
		while (!__isaligned(str, sizeof(__m128i)) && *str)
			if (*str++ == c)
				ptr = (char *)(str - 1);
	}
	longword = (__m128i *)__builtin_assume_aligned(str, sizeof(__m128i));
	while (longword)
	{
		chunk = _mm_load_si128(longword);
		if (_mm_cmpistrc(set, chunk, FLAG))
			ptr = (char *)longword + _mm_cmpistri(set, chunk, FLAG);
		else if (_mm_cmpistrz(set, chunk, FLAG))
			break ;
		++longword;
	}
	return (ptr);
}
