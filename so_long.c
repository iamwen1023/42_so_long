#include "includes/so_long.h"

int	handle_input(int key, t_allimg **allimg)
{
	int p;
	int	x;
	int y;
	int p_cur;
	static int	step = 0;
	
	p = (*allimg)->position->p;
	x = (*allimg)->position->x;
	y = (*allimg)->position->y;
	p_cur = p;
	if (key == KEY_A)
		new_imgandpostion(allimg,&step, p_cur, p - 1, x-1 , x , y , y);
	else if (key == KEY_D)
		new_imgandpostion(allimg,&step, p_cur, p + 1, x+1 , x , y , y);
	else if (key == KEY_W)
		new_imgandpostion(allimg,&step, p_cur, p - 1 - (*allimg)->position->col , x , x , y-1 , y);
	else if (key == KEY_S)
		new_imgandpostion(allimg,&step, p_cur, p + 1 + (*allimg)->position->col , x , x , y+1 , y);
	if ((*allimg)->g_map[(*allimg)->position->p] == 'E' && check_gmap((*allimg)->g_map) == 0)
		free_all(allimg);
	printf("Current number of movements:%d\n", step);
	return (0);
}

int	close_game(int keycode, t_allimg *allimg)
{
	if (keycode == KEY_ESC)
		free_all(&allimg);
	return 0;
}
int	close_game_mouse(t_allimg *allimg)
{
	free_all(&allimg);
	return 0;
}

 

void	in_the_windows(t_map *map,char	*g_map)
{
	t_allimg *allimg;
	t_w		w_p;

	w_p.mlx = mlx_init();
	if (!w_p.mlx)
		error_meg(0, ERRO, g_map);
	w_p.win = mlx_new_window(w_p.mlx, 60 * map->col_curr, 60 * map->row, "Diamond Dig!");
	if (!w_p.win)
	{
		free(w_p.mlx);
		error_meg(0, ERRO, g_map);
	}
	allimg = 0;
	initial_map(map, &w_p, &allimg, g_map);
	mlx_key_hook(w_p.win, &handle_input, &allimg);
	mlx_hook(w_p.win, 2, 1L<<0, &close_game, allimg);
	mlx_hook(w_p.win, 17, 1L<<0, &close_game_mouse, allimg);
	mlx_loop(w_p.mlx);
	free(g_map);
}

int main(int ac, char**av)
{
	t_map	map;
	static char	*g_map = 0;

	if (ac != 2 || check_extension(av[1], g_map))
		error_meg(0, ER_FILE, g_map);
	map = read_map(av[1], &g_map);
	in_the_windows(&map, g_map);
	return (0);
}
