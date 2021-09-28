/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:24:58 by wlo               #+#    #+#             */
/*   Updated: 2021/05/27 11:49:23 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	if_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	index;
	char	*arr;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	while (len != 0 && s1[len - 1] && if_set(s1[len - 1], set) == 1)
		len--;
	while (*s1 && if_set(*s1, set) == 1 && len != 0)
	{
		len--;
		s1++;
	}
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	index = 0;
	while (*s1 && index < len)
	{
		arr[index] = *s1++;
		index++;
	}
	arr[index] = '\0';
	return (arr);
}
