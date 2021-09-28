/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:36:13 by wlo               #+#    #+#             */
/*   Updated: 2021/05/25 10:11:59 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*origin;
	size_t			i;

	origin = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*origin = 0;
		origin++;
		i++;
	}
}
