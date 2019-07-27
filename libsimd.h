/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsimd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:34:53 by thflahau          #+#    #+#             */
/*   Updated: 2019/07/23 13:15:00 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBSIMD_H__
# define __LIBSIMD_H__

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

# define __inline					__attribute__((always_inline))
# define __isaligned(ptr, x)		(!((size_t)ptr & (x - 1)))

typedef struct			s_listhead {
	struct s_listhead	*next;
	struct s_listhead	*prev;
}						t_listhead;

/*
**	Strings
*/
int				ft_strcmp(char const *, char const *);
void			ft_putstr(char const *) __inline;
size_t			ft_strlen(char const *);
char			*ft_strrchr(char const *, int);

/*
**	Memory
*/
void			ft_bzero(void *, size_t);
void			ft_memcpy(void *, void *, size_t);
void			*ft_memset(void *, int, size_t);

/*
**	Linked list
*/
void			ft_list_init_head(t_listhead *);
void			ft_list_add_tail(t_listhead *, t_listhead *);
void			ft_list_delete(t_listhead *, void *(*ptr)(t_listhead *));
void			ft_list_push(t_listhead *, t_listhead *);
void			ft_list_pop(t_listhead *, void *(ptr)(t_listhead *));
void			ft_list_add(t_listhead *, t_listhead *, t_listhead *);
size_t			ft_list_size(t_listhead const *);

/*
**	Bits
*/
uint16_t		ft_swap_uint16(uint16_t) __inline;
uint32_t		ft_swap_uint32(uint32_t) __inline;

#endif /* __LIBSIMD_H__ */
