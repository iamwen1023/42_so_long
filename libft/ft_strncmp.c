/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:30:36 by wlo               #+#    #+#             */
/*   Updated: 2021/05/25 10:32:37 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*unsi_s1;
	unsigned char	*unsi_s2;

	unsi_s1 = (unsigned char *)s1;
	unsi_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && unsi_s1[i] && unsi_s2[i])
	{
		if (unsi_s1[i] != unsi_s2[i])
			return (unsi_s1[i] - unsi_s2[i]);
		i++;
	}
	if ((unsi_s1[i] == '\0' || unsi_s2[i] == '\0') && i < n)
		return (unsi_s1[i] - unsi_s2[i]);
	return (0);
}
