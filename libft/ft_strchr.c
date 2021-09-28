/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:08:08 by wlo               #+#    #+#             */
/*   Updated: 2021/05/26 13:37:54 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ch_s;

	ch_s = (unsigned char *)s;
	while (*ch_s)
	{
		if ((*ch_s) == (unsigned char)c)
			return ((char *)ch_s);
		ch_s++;
	}
	if ((*ch_s) == '\0' && c == '\0')
		return ((char *)ch_s);
	return (0);
}
