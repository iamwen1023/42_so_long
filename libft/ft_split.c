/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:35:32 by wlo               #+#    #+#             */
/*   Updated: 2021/05/27 13:44:20 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	if_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	count_w(const char *s, char c)
{
	int	state;
	int	count;

	state = 1;
	count = 0;
	while (*s)
	{
		if (if_sep(*s, c) == 1)
			state = 1;
		else
		{
			if (state == 1)
				count++;
			state = 0;
		}
		s++;
	}
	return (count);
}

int	len_w(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s && if_sep(*s, c) == 0)
	{
		count++;
		s++;
	}
	return (count);
}

void	ft_split_2(char ***arr, char const *s, char c, int count_ws)
{
	int	index;
	int	len_ws;
	int	i;

	index = 0;
	while (index < count_ws)
	{
		while (*s && if_sep(*s, c) == 1)
			s++;
		len_ws = len_w(s, c);
		(*arr)[index] = (char *)malloc((len_ws + 1) * sizeof(char));
		if (!(*arr))
			return ;
		i = 0;
		while (*s && i < len_ws)
			(*arr)[index][i++] = *s++;
		(*arr)[index][i] = '\0';
		index++;
	}
	(*arr)[index] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count_ws;

	if (!s)
		return (0);
	count_ws = count_w(s, c);
	arr = (char **)malloc((count_ws + 1) * sizeof(char *));
	if (!arr)
		return (0);
	ft_split_2(&arr, s, c, count_ws);
	return (arr);
}
