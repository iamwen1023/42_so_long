/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:12:41 by wlo               #+#    #+#             */
/*   Updated: 2021/05/26 10:22:22 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
