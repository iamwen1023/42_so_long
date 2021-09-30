/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:16:37 by wlo               #+#    #+#             */
/*   Updated: 2021/09/30 15:37:19 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_wall(int fd, t_map *map, char *g_map)
{
	int	i;
	int	r;
	int	c;
	int	c2;

	i = -1;
	r = map->row;
	c = map->col_curr;
	c2 = c + 1;
	while (++i < c)
	{
		if (g_map[i] != '1' || g_map[i + (r - 1) * (c + 1)] != '1')
			error_meg(fd, ER_WALL, g_map);
	}
	i = -1;
	while (++i < r - 1)
	{
		if (g_map[(i + 1) * (c2)] != '1' || g_map[(c - 1) + i * (c2)] != '1')
			error_meg(fd, ER_WALL, g_map);
	}
	return (0);
}

int	check_elem(int fd, t_map *map, char *g_map)
{
	int	i;

	i = -1;
	while (g_map[++i])
	{
		if (g_map[i] == 'C')
			map->n_c++;
		else if (g_map[i] == 'E')
			map->n_e++;
		else if (g_map[i] == 'P')
			map->n_p++;
	}
	if (map->n_p > 1)
		error_meg(fd, ER_P, g_map);
	if (map->n_c == 0 || map->n_e == 0 || map->n_p == 0)
		error_meg(fd, ER_ELE, g_map);
	return (0);
}

int	check_map(int fd, t_map *map, char *g_map)
{
	int	i;

	i = -1;
	while (g_map[++i])
	{
		check_character(fd, g_map[i], g_map);
		if (g_map[i] != '\n')
			map->col_curr++;
		else if (g_map[i + 1] && g_map[i] == '\n')
		{
			if (map->row == 1)
				map->col_b = map->col_curr;
			else
			{
				if (map->col_b != map->col_curr)
					error_meg(fd, ER_RECTAN, g_map);
				map->col_b = map->col_curr;
			}
			map->col_curr = 0;
			map->row++;
		}
	}
	if (map->row == map->col_b || map->col_b != map->col_curr)
		error_meg(fd, ER_RECTAN, g_map);
	return (0);
}

t_map	read_map(char *av, char **g_map)
{
	int		fd;
	t_map	map;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_meg(0, -1, 0);
	if (parse_map(fd, g_map) < 0)
		error_meg(fd, -1, 0);
	if (!(*g_map))
		error_meg(fd, -1, 0);
	init_map(&map);
	check_map(fd, &map, *g_map);
	check_wall(fd, &map,*g_map);
	check_elem(fd, &map,*g_map);
	close(fd);
	return (map);
}
