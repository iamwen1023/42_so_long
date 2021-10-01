/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:29:44 by wlo               #+#    #+#             */
/*   Updated: 2021/10/01 17:38:31 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	(*allimg)->m = w_p->m;
	(*allimg)->w = w_p->w;
	(*allimg)->b = mlx_xpm_file_to_image(w_p->m, PH_WALL, &wth, &hgt);
	(*allimg)->f = mlx_xpm_file_to_image(w_p->m, PH_FLOOR2, &wth, &hgt);
	(*allimg)->d = mlx_xpm_file_to_image(w_p->m, PH_DIAMON, &wth, &hgt);
	(*allimg)->e = mlx_xpm_file_to_image(w_p->m, PH_EXIT, &wth, &hgt);
	(*allimg)->p = mlx_xpm_file_to_image(w_p->m, PH_PLAYER, &wth, &hgt);
	(*allimg)->ep = mlx_xpm_file_to_image(w_p->m, PH_EX_PY, &wth, &hgt);
	(*allimg)->position = (t_position *)malloc(sizeof(*(*allimg)->position));
	if (!(*allimg)->position)
		return ;
	init_postion(map, &(*allimg)->position, g_map);
	(*allimg)->g_map = g_map;
}

void	initial_map(t_map *map, t_w	*p, t_allimg **a, char *g_map)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	init_img(a, p, map, g_map);
	while (++y < map->row)
	{
		x = -1;
		while (++x < map->col_curr)
		{
			i = x + (y * map->col_curr + y);
			if (g_map[i] == '0')
				mlx_put_image_to_window(p->m, p->w, (*a)->f, x * S, y * S);
			else if (g_map[i] == '1')
				mlx_put_image_to_window(p->m, p->w, (*a)->b, x * S, y * S);
			else if (g_map[i] == 'C')
				mlx_put_image_to_window(p->m, p->w, (*a)->d, x * S, y * S);
			else if (g_map[i] == 'P')
				mlx_put_image_to_window(p->m, p->w, (*a)->p, x * S, y * S);
			else if (g_map[i] == 'E')
				mlx_put_image_to_window(p->m, p->w, (*a)->e, x * S, y * S);
		}
	}
}

void	ne_po_2(t_allimg **a, t_p p)
{
	if ((*a)->g_map[p.p] == 'E')
	{
		mlx_put_image_to_window((*a)->m, (*a)->w, (*a)->ep, p.x1 * S, p.y1 * S);
		mlx_put_image_to_window((*a)->m, (*a)->w, (*a)->f, p.x2 * S, p.y2 * S);
	}
	else if ((*a)->g_map[p.p] == '0' || (*a)->g_map[p.p] == 'C'
		|| (*a)->g_map[p.p] == 'P' || (*a)->g_map[p.p] == 'E')
	{
		mlx_put_image_to_window((*a)->m, (*a)->w, (*a)->p, p.x1 * S, p.y1 * S);
		mlx_put_image_to_window((*a)->m, (*a)->w, (*a)->f, p.x2 * S, p.y2 * S);
	}
}

void	ne_po(t_allimg **a, int *step, t_p p)
{
	if ((*a)->g_map[p.p] == '1')
		return ;
	if ((*a)->g_map[p.curr] == 'E')
	{
		mlx_put_image_to_window((*a)->m, (*a)->w, (*a)->p, p.x1 * S, p.y1 * S);
		mlx_put_image_to_window((*a)->m, (*a)->w, (*a)->e, p.x2 * S, p.y2 * S);
	}
	else
		ne_po_2(a, p);
	if ((*a)->g_map[p.curr] == 'C')
		(*a)->g_map[p.curr] = '0';
	if ((*a)->g_map[p.curr] == 'P')
		(*a)->g_map[p.curr] = '0';
	(*a)->position->p = p.p;
	(*a)->position->x = p.x1;
	(*a)->position->y = p.y1;
	*step = *step + 1;
}
