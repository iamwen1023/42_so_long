/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:08:08 by wlo               #+#    #+#             */
/*   Updated: 2021/05/25 10:20:43 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*origin;
	size_t			i;

	origin = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*origin = c;
		origin++;
		i++;
	}
	return (s);
}
