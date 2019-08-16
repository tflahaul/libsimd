/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:19:54 by thflahau          #+#    #+#             */
/*   Updated: 2019/08/16 15:41:08 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libsimd.h"

int					main(int argc, char **argv)
{
	char			*ptr;

	if (argc != 3)
		return (EXIT_FAILURE);
	printf("argv[1]:len = %zu\n", ft_strlen(argv[1]));
	printf("argv[2]:len = %zu\n", ft_strlen(argv[2]));
	printf("[%s]\t", (ptr = ft_strrchr(argv[1], argv[2][0])));
	printf("[%s]\n", (ptr = ft_strrchr(argv[2], argv[1][0])));

	ft_memcpy(argv[1], argv[2], ft_strlen(argv[1]));
	printf("argv[1] = [%s]\targv[2] = [%s]\n", argv[1], argv[2]);
	ft_memset(argv[2], argv[1][0], ft_strlen(argv[2]));
	printf("argv[1] = [%s]\targv[2] = [%s]\n", argv[1], argv[2]);
	ft_bzero(argv[1], ft_strlen(argv[2]));
	printf("argv[1] = [%s]\n", argv[1]);
	ft_bzero(argv[2], 0);
	printf("argv[2] = [%s]\n", argv[2]);
	return (0);
}
