/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:38:09 by wlo               #+#    #+#             */
/*   Updated: 2021/05/25 10:30:12 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	index;
	char			*arr;

	if (!s)
		return (0);
	len = (unsigned int)ft_strlen(s);
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	index = 0;
	while (*s && index < len && f)
	{	
		arr[index] = f(index, *s);
		index++;
		s++;
	}
	arr[index] = '\0';
	return (arr);
}
