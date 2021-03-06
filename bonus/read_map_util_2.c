/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_util_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:13:32 by wlo               #+#    #+#             */
/*   Updated: 2021/09/30 15:37:11 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_character(int fd, char c, char *g_map)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E' && c != '\n')
		error_meg(fd, ER_CHAR, g_map);
	return (0);
}

int	parse_map(int fd, char **g_map)
{
	char	buffer[2];
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, 1);
		buffer[1] = '\0';
		if (ret < 0 )
			break ;
		else if (ret == 0)
			return (0);
		if ((*g_map) == 0)
		{
			(*g_map) = malloc(sizeof(char) * 2);
			if (!(*g_map))
				return (-1);
			(*g_map)[0] = buffer[0];
			(*g_map)[1] = '\0';
		}
		else
			(*g_map) = ft_strjoin_map(&(*g_map), buffer);
	}
	return (1);
}
