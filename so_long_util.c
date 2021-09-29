/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:29:44 by wlo               #+#    #+#             */
/*   Updated: 2021/09/29 18:03:08 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_postion(t_map *map, t_position **position, char *g_map)
{
	int	x;
	int	y;
	int	p;

	(*position)->col = map->col_curr;
	(*position)->row = map->row;
	y = 0;
	p = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col_curr)
		{
			p = x + (y * map->col_curr + y);
			if (g_map[p] == 'P')
			{
				((*position)->x = x);
				((*position)->y = y);
				((*position)->p = p);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_img(t_allimg **allimg, t_w	*w_p, t_map *map, char *g_map)
{
	int	wth;
	int	hgt;

	(*allimg) = (t_allimg *)malloc(sizeof(**allimg));
	if (!allimg)
		return ;
	(*allimg)->mlx = w_p->mlx;
	(*allimg)->win = w_p->win;
	(*allimg)->wall = mlx_xpm_file_to_image(w_p->mlx, PH_WALL, &wth, &hgt);
	(*allimg)->floor = mlx_xpm_file_to_image(w_p->mlx, PH_FLOOR2, &wth, &hgt);
	(*allimg)->diamond = mlx_xpm_file_to_image(w_p->mlx, PH_DIAMON, &wth, &hgt);
	(*allimg)->exit = mlx_xpm_file_to_image(w_p->mlx, PH_EXIT, &wth, &hgt);
	(*allimg)->player = mlx_xpm_file_to_image(w_p->mlx, PH_PLAYER, &wth, &hgt);
	(*allimg)->ex_pl = mlx_xpm_file_to_image(w_p->mlx, PH_EX_PY, &wth, &hgt);
	(*allimg)->position = (t_position *)malloc(sizeof(*(*allimg)->position));
	if (!(*allimg)->position)
		return ;
	init_postion(map, &(*allimg)->position, g_map);
	(*allimg)->g_map = g_map;
}

void	initial_map(t_map *map, t_w	*w_p, t_allimg **allimg, char *g_map)
{
	int x;
	int y;
	int p;

	y = -1;
	init_img(allimg, w_p, map, g_map);
	while(++y < map->row)
	{
		x = -1;
		while(++x < map->col_curr)
		{
			p = x + (y * map->col_curr + y);
			if (g_map[p] == '0')
			 	mlx_put_image_to_window(w_p->mlx, w_p->win, (*allimg)->floor, x * 60, y *60);
			else if (g_map[p] == '1')
				mlx_put_image_to_window(w_p->mlx, w_p->win, (*allimg)->wall, x * 60, y *60);
			else if (g_map[p] == 'C')
				mlx_put_image_to_window(w_p->mlx, w_p->win, (*allimg)->diamond, x * 60, y *60);
			else if (g_map[p] == 'P')
				mlx_put_image_to_window(w_p->mlx, w_p->win, (*allimg)->player, x * 60, y *60);
			else if (g_map[p] == 'E')
				mlx_put_image_to_window(w_p->mlx, w_p->win, (*allimg)->exit, x * 60, y *60);
		}
	}
}

void new_imgandpostion(t_allimg **allimg, int *step,int current, int p, int x1, int x2, int y1, int y2)
{
	if ((*allimg)->g_map[p] == '1')
		return ;
	if ((*allimg)->g_map[current] == 'E')
	{
		mlx_put_image_to_window((*allimg)->mlx, (*allimg)->win, (*allimg)->player,x1 * 60, y1 *60);
		mlx_put_image_to_window((*allimg)->mlx, (*allimg)->win, (*allimg)->exit, x2 * 60, y2 *60);	
	}
	else if ((*allimg)->g_map[p] == 'E')
	{
		mlx_put_image_to_window((*allimg)->mlx, (*allimg)->win, (*allimg)->ex_pl, x1 * 60, y1 *60);
		mlx_put_image_to_window((*allimg)->mlx, (*allimg)->win, (*allimg)->floor, x2 * 60, y2 *60);
	}
	else if ((*allimg)->g_map[p] == '0' || (*allimg)->g_map[p] == 'C'|| (*allimg)->g_map[p] == 'P' || (*allimg)->g_map[p] == 'E')
	{
		mlx_put_image_to_window((*allimg)->mlx, (*allimg)->win, (*allimg)->player,x1 * 60, y1 *60);
		mlx_put_image_to_window((*allimg)->mlx, (*allimg)->win, (*allimg)->floor, x2 * 60, y2 *60);
	}
	if ((*allimg)->g_map[current] == 'C')
		(*allimg)->g_map[current] = '0';
	(*allimg)->position->p = p;
	(*allimg)->position->x = x1;
	(*allimg)->position->y = y1;
	*step = *step + 1;
}
