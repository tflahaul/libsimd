/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsimd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:34:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/16 15:43:54 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBSIMD_H__
# define __LIBSIMD_H__

# include <smmintrin.h>
# include <sys/types.h>
# include <stdint.h>

# ifdef __GNUC__
#  define __CCV (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#  if __CCV > 29600
#   define __likely(x)				__builtin_expect((x), 1)
#   define __unlikely(x)			__builtin_expect((x), 0)

#  else
#   define __likely(x)				(x)
#   define __unlikely(x)			(x)
#  endif /* __CCV */

# else
#  error "Your compiler does not use the C preprocessor, try using GCC"
# endif /* __GNUC__ */

# define __isaligned(ptr, x)		(!((size_t)ptr & (x - 1)))

# define FLAG_SB	(_SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_LEAST_SIGNIFICANT)
# define FLAG_SBM	(_SIDD_SBYTE_OPS | _SIDD_MOST_SIGNIFICANT)
# define M128_SZ	16

/*
**			Strings
*/

size_t					ft_strlen(char const *str)
{
	char				*ptr = (char *)str;
	__m128i				chunk;
	__m128i				*longword;
	__m128i const		set = _mm_setzero_si128();

	if (__unlikely(!str[0]))
		return (0);
	longword = (__m128i *)__builtin_assume_aligned(ptr, M128_SZ);
	while (longword)
	{
		chunk = _mm_loadu_si128(longword);
		if (_mm_cmpistrc(set, chunk, FLAG_SB))
		{
			ptr = (char *)longword + _mm_cmpistri(set, chunk, FLAG_SB);
			return ((size_t)(ptr - (char *)str));
		}
		++longword;
	}
	return (0);
}

char					*ft_strrchr(char const *str, int c)
{
	char				*ptr = NULL;
	__m128i				chunk;
	__m128i				*longword;
	__m128i const		set = _mm_setr_epi16(c, 0, 0, 0, 0, 0, 0, 0);

	longword = (__m128i *)__builtin_assume_aligned(str, M128_SZ);
	while (longword)
	{
		chunk = _mm_loadu_si128(longword);
		if (_mm_cmpistrc(set, chunk, FLAG_SBM))
			ptr = (char *)longword + _mm_cmpistri(set, chunk, FLAG_SBM);
		else if (_mm_cmpistrz(set, chunk, FLAG_SBM))
			break ;
		++longword;
	}
	return (ptr);
}

/*
**			Memory
*/

void					ft_bzero(void *ptr, size_t size)
{
	unsigned char		*mem;
	__m128i				*longword = (__m128i *)ptr;
	__m128i const		set = _mm_setzero_si128();

	while (size >= M128_SZ)
	{
		_mm_storeu_si128(longword++, set);
		size -= M128_SZ;
	}
	mem = (unsigned char *)longword;
	while (size-- > 0)
		*mem++ = 0;
}

void					ft_memcpy(void *dst, void *src, size_t len)
{
	unsigned char		*ptd;
	unsigned char		*pts;
	__m128i				*dstlongword = (__m128i *)dst;
	__m128i				*srclongword = (__m128i *)src;

	while (len >= M128_SZ)
	{
		_mm_storeu_si128(dstlongword++, _mm_loadu_si128(srclongword++));
		len -= M128_SZ;
	}
	ptd = (unsigned char *)dstlongword;
	pts = (unsigned char *)srclongword;
	while (len-- > 0)
		*ptd++ = *pts++;
}

void					*ft_memset(void *dst, int c, size_t size)
{
	unsigned char		*ptr;
	__m128i				*longword = (__m128i *)dst;
	__m128i const		set = _mm_set1_epi8(c);

	while (size >= M128_SZ)
	{
		_mm_storeu_si128(longword++, set);
		size -= M128_SZ;
	}
	ptr = (unsigned char *)longword;
	while (size-- > 0)
		*ptr++ = c;
	return (dst);
}

/*
**			Bits
*/

inline uint16_t			ft_swap_uint16(uint16_t nb)
{
	return (((nb & 0x00ff) >> 8) | ((nb & 0xff00) << 8));
}

inline uint32_t			ft_swap_uint32(uint32_t nb)
{
	return (((nb & 0xff000000) >> 24) | ((nb & 0x00ff0000) >> 8) |\
			((nb & 0x0000ff00) << 8) | ((nb & 0x000000ff) << 24));
}

#endif /* __LIBSIMD_H__ */
