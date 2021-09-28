/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:14:25 by wlo               #+#    #+#             */
/*   Updated: 2021/05/25 10:26:56 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*arr;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	arr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!arr)
		return (0);
	ft_strlcpy(arr, s1, len_s1 + len_s2 + 1);
	ft_strlcat(arr, s2, len_s1 + len_s2 + 1);
	arr[len_s1 + len_s2] = '\0';
	return (arr);
}
