/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:51:41 by wlo               #+#    #+#             */
/*   Updated: 2021/09/21 16:18:23 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(char *s, int c)
{
	unsigned char	*ch_s;

	if (!s)
		return (0);
	ch_s = (unsigned char *)s;
	while (*ch_s)
	{
		if ((*ch_s) == (unsigned char)c)
			return ((char *)(ch_s));
		ch_s++;
	}
	if ((*ch_s) == '\0' && c == '\0')
		return ((char *)ch_s);
	return (0);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char		*arr;
	size_t		i;
	size_t		len_s;
	size_t		rlen;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if ((size_t)start >= len_s)
		rlen = 0;
	else if (start + len > len_s)
		rlen = len_s - start;
	else
		rlen = len;
	arr = malloc((rlen + 1) * sizeof(char));
	if (!arr)
		return (0);
	i = 0;
	while (i < rlen && s[start])
	{
		arr[i] = s[start++];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
