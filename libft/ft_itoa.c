/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:57:40 by wlo               #+#    #+#             */
/*   Updated: 2021/05/25 10:14:48 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_count(long n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_itoa_2(long long_n, int len, char **arr)
{
	int		i;

	i = len - 1;
	while (long_n >= 10)
	{
		(*arr)[i] = long_n % 10 + '0';
		long_n = long_n / 10;
		i--;
	}
	(*arr)[i] = long_n % 10 + '0';
	(*arr)[len] = '\0';
}

char	*ft_itoa(int n)
{
	long	long_n;
	int		len;
	char	*arr;

	long_n = (long)n;
	if (long_n < 0)
		long_n = long_n * (-1);
	len = digit_count(long_n);
	if (n < 0)
		len = len + 1;
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	ft_itoa_2(long_n, len, &arr);
	if (n < 0)
		arr[0] = '-';
	return (arr);
}
