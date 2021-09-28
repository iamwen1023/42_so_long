/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:33:27 by wlo               #+#    #+#             */
/*   Updated: 2021/05/26 13:55:58 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	size_t			index;
	unsigned char	*ch_s;

	ch_s = (unsigned char *)s;
	if ((*ch_s) == '\0' && c == '\0')
		return ((char *)ch_s);
	len = ft_strlen(s);
	if (len == 0)
		return (0);
	index = len - 1;
	while (index > 0)
	{
		if (ch_s[index] == (unsigned char)c)
			return ((char *)&ch_s[index]);
		index--;
	}
	if (ch_s[index] == (unsigned char)c)
		return ((char *)&ch_s[index]);
	if (c == 0)
		return ((char *)&ch_s[len]);
	return (0);
}
