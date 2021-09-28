/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:52:55 by wlo               #+#    #+#             */
/*   Updated: 2021/05/24 12:35:37 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*ch_str1;
	unsigned char	*ch_str2;
	size_t			i;

	ch_str1 = (unsigned char *)str1;
	ch_str2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (ch_str1[i] != ch_str2[i])
			return (ch_str1[i] - ch_str2[i]);
		i++;
	}
	return (0);
}
