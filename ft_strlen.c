/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:38:17 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:17:36 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <smmintrin.h>
#include "libsimd.h"

#define FLAG (_SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_LEAST_SIGNIFICANT)

size_t				ft_strlen(char const *str)
{
	char			*ptr;
	__m128i			chunk;
	__m128i			*longword;
	__m128i const	set = _mm_setzero_si128();

	if (__unlikely(!str[0]))
		return (0);
	ptr = (char *)str;
	longword = (__m128i *)ptr;
	while (longword)
	{
		chunk = _mm_loadu_si128(longword);
		if (_mm_cmpistrc(set, chunk, FLAG))
		{
			ptr = (char *)longword + _mm_cmpistri(set, chunk, FLAG);
			return ((size_t)(ptr - (char *)str));
		}
		++longword;
	}
	return (0);
}
