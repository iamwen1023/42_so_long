/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:30:08 by wlo               #+#    #+#             */
/*   Updated: 2021/09/30 16:52:46 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int key, t_allimg **a)
{
	int			p;
	int			x;
	int			y;
	static int	step = 0;
	int			r;

	p = (*a)->position->p;
	x = (*a)->position->x;
	y = (*a)->position->y;
	r = (*a)->position->row * 60;
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
	if (step > 0)
		mlx_string_put((*a)->m, (*a)->w, 120, r, 0x000000, ft_itoa(step - 1));
	mlx_string_put((*a)->m, (*a)->w, 120, r, 0xFFFFFF, ft_itoa(step));
	printf("Current number of movements:%d\n", step);
	return (0);
}

int	close_game(int keycode, t_allimg *allimg)
{
	if (keycode == KEY_ESC)
		free_all(&allimg);
	return (0);
}

int	close_game_mouse(t_allimg *allimg)
{
	free_all(&allimg);
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
	mlx_string_put(w_p.m, w_p.w, 0, (map->row) * 60, 0xFFFFFF, "Movements:");
	mlx_key_hook(w_p.w, &handle_input, &allimg);
	mlx_hook(w_p.w, 2, 1L << 0, &close_game, allimg);
	mlx_hook(w_p.w, 17, 1L << 0, &close_game_mouse, allimg);
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
