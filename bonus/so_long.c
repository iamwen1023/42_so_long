/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:30:08 by wlo               #+#    #+#             */
/*   Updated: 2021/10/01 17:57:10 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int key, t_allimg **a)
{
	int			p;
	int			x;
	int			y;
	static int	step = 0;

	p = (*a)->position->p;
	x = (*a)->position->x;
	y = (*a)->position->y;
	if (key == KEY_A)
		ne_po(a, &step, (t_p){p, p - 1, x - 1, x, y, y});
	else if (key == KEY_D)
		ne_po(a, &step, (t_p){p, p + 1, x + 1, x, y, y});
	else if (key == KEY_W)
		ne_po(a, &step, (t_p){p, p - 1 - (*a)->position->col, x, x, y - 1, y});
	else if (key == KEY_S)
		ne_po(a, &step, (t_p){p, p + 1 + (*a)->position->col, x, x, y + 1, y});
	if ((*a)->g_map[(*a)->position->p] == 'E' && check_gmap((*a)->g_map) == 0)
		free_all(a);
	if ((*a)->g_map[(*a)->position->p] != 'E')
		(*a)->g_map[(*a)->position->p] = 'P';
	if (show_move(a, step))
		free_all(a);
	return (0);
}

void	curr_map_2(t_allimg *a, int x, int y, int i)
{
	if (a->g_map[i] == '1')
		mlx_put_image_to_window(a->m, a->w, a->b, x * S, y * S);
	else if (a->g_map[i] == 'C')
		mlx_put_image_to_window(a->m, a->w, a->d, x * S, y * S);
	else if (a->g_map[i] == 'P')
		mlx_put_image_to_window(a->m, a->w, a->p, x * S, y * S);
	else if (a->g_map[i] == 'E')
		mlx_put_image_to_window(a->m, a->w, a->e, x * S, y * S);
}

int	curr_map(t_allimg *a)
{
	int	x;
	int	y;
	int	i;
	int	l;

	y = -1;
	l = a->position->row * 60 + 15;
	while (++y < a->position->row)
	{
		x = -1;
		while (++x < a->position->col)
		{
			i = x + (y * a->position->col + y);
			if (a->g_map[i] == 'E' && a->position->p == i)
				mlx_put_image_to_window(a->m, a->w, a->ep, x * S, y * S);
			else if (a->g_map[i] == '0')
				mlx_put_image_to_window(a->m, a->w, a->f, x * S, y * S);
			else
				curr_map_2(a, x, y, i);
		}
	}
	mlx_string_put(a->m, a->w, 0, l, 0x000000, "Movements:");
	mlx_string_put(a->m, a->w, 0, l, 0xFFFFFF, "Movements:");
	return (0);
}

void	in_the_windows(t_map *map, char	*g_map)
{
	t_allimg	*allimg;
	t_w			w_p;
	int			col;

	col = map->col_curr;
	w_p.m = mlx_init();
	if (!w_p.m)
		error_meg(0, ERRO, g_map);
	w_p.w = mlx_new_window(w_p.m, S * col, S * (map->row + 1), "Diamond Dig!");
	if (!w_p.w)
	{
		free(w_p.m);
		error_meg(0, ERRO, g_map);
	}
	allimg = 0;
	initial_map(map, &w_p, &allimg, g_map);
	mlx_key_hook(w_p.w, &handle_input, &allimg);
	mlx_hook(w_p.w, 2, 1L << 0, &close_game, allimg);
	mlx_hook(w_p.w, 17, 1L << 0, &close_game_mouse, allimg);
	mlx_loop_hook(w_p.m, &curr_map, allimg);
	mlx_loop(w_p.m);
	free(g_map);
}

int	main(int ac, char**av)
{
	t_map		map;
	static char	*g_map = 0;

	if (ac != 2 || check_extension(av[1], g_map))
		error_meg(0, ER_FILE, g_map);
	map = read_map(av[1], &g_map);
	in_the_windows(&map, g_map);
	return (0);
}
