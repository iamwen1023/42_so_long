#include "so_long.h"

typedef struct	s_position 
{
	int		p;
	int		x;
	int		y;
	int		col;
    int		row;

}		t_position;

typedef struct s_allimg
{
	void	*wall;
	void	*floor;
	void	*diamond;
	void	*exit;
	void	*player;
	void	*ex_player;
	t_position *position;
	void	*mlx;
	void	*win;
	char	*g_map;
}	t_allimg;


void	init_postion(t_map *map, t_position **position, char *g_map)
{
	int x = 0;
	int y = 0;
	int p = 0;


	(*position)->col = map->col_curr;
	(*position)->row = map->row;
	while(y < map->row)
	{
		x = 0;
		while(x < map->col_curr)
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
void	init_img(t_allimg **allimg, void *mlx, void	*win, t_map *map, char *g_map)
{
	int 	wth;
	int 	hgt;

	(*allimg) = (t_allimg *)malloc(sizeof(**allimg));
	if (!allimg)
		return ;
	(*allimg)->mlx = mlx;
	(*allimg)->win = win;
	(*allimg)->wall = mlx_xpm_file_to_image(mlx, PH_WALL, &wth, &hgt);
	(*allimg)->floor= mlx_xpm_file_to_image(mlx, PH_FLOOR2, &wth, &hgt);
	(*allimg)->diamond= mlx_xpm_file_to_image(mlx, PH_DIAMON, &wth, &hgt);
	(*allimg)->exit= mlx_xpm_file_to_image(mlx, PH_EXIT, &wth, &hgt);
	(*allimg)->player= mlx_xpm_file_to_image(mlx, PH_PLAYER, &wth, &hgt);
	(*allimg)->ex_player= mlx_xpm_file_to_image(mlx, PH_EX_PY, &wth, &hgt);
	(*allimg)->position =  (t_position *)malloc(sizeof(*(*allimg)->position));
	if (!(*allimg)->position)
		return ;
	init_postion(map, &(*allimg)->position, g_map);
	(*allimg)->g_map = g_map;
}

void	initial_map(t_map *map, void *mlx ,void *win ,t_allimg **allimg, char *g_map)
{
	int x = 0;
	int y = 0;
	int p = 0;

	init_img(allimg, mlx, win, map, g_map);
	while(y < map->row)
	{
		x = 0;
		while(x < map->col_curr)
		{
			p = x + (y * map->col_curr + y);
			if (g_map[p] == '0')
			 	mlx_put_image_to_window(mlx, win, (*allimg)->floor, x * 60, y *60);
			else if (g_map[p] == '1')
				mlx_put_image_to_window(mlx, win, (*allimg)->wall, x * 60, y *60);
			else if (g_map[p] == 'C')
				mlx_put_image_to_window(mlx, win, (*allimg)->diamond, x * 60, y *60);
			else if (g_map[p] == 'P')
				mlx_put_image_to_window(mlx, win, (*allimg)->player, x * 60, y *60);
			else if (g_map[p] == 'E')
				mlx_put_image_to_window(mlx, win, (*allimg)->exit, x * 60, y *60);
			x++;
		}
		y++;
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
		mlx_put_image_to_window((*allimg)->mlx, (*allimg)->win, (*allimg)->ex_player, x1 * 60, y1 *60);
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
void free_all(t_allimg **allimg)
{
	mlx_destroy_image((*allimg)->mlx, (*allimg)->diamond);
	mlx_destroy_image((*allimg)->mlx, (*allimg)->exit);
	mlx_destroy_image((*allimg)->mlx, (*allimg)->player);
	mlx_destroy_image((*allimg)->mlx, (*allimg)->floor);
	mlx_destroy_image((*allimg)->mlx, (*allimg)->wall);
	mlx_destroy_image((*allimg)->mlx, (*allimg)->ex_player);
	free((*allimg)->position);
	free((*allimg)->g_map);
	mlx_destroy_window((*allimg)->mlx, (*allimg)->win);
	//mlx_destroy_display((*allimg)->mlx);
	free((*allimg)->mlx);
	free((*allimg));
	exit(0);
}
int chech_gmap(char *g_map)
{
	int	i;
	int	collect;

	i = -1;
	collect = 0;
	while(g_map[++i])
	{
		if(g_map[i] == 'C')
			collect++;
	}
	return (collect);
}
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
	// printf("key:%d\n", key);
	// printf("position:%d\n", p);
	if (key == 0)
		new_imgandpostion(allimg,&step, p_cur, p - 1, x-1 , x , y , y);
	else if (key == 2)
		new_imgandpostion(allimg,&step, p_cur, p + 1, x+1 , x , y , y);
	else if (key == 13)
		new_imgandpostion(allimg,&step, p_cur, p - 1 - (*allimg)->position->col , x , x , y-1 , y);
	else if (key == 1)
		new_imgandpostion(allimg,&step, p_cur, p + 1 + (*allimg)->position->col , x , x , y+1 , y);
	if ((*allimg)->g_map[(*allimg)->position->p] == 'E' && chech_gmap((*allimg)->g_map) == 0)
	{
		free_all(allimg);
		printf("exit_game()\n");
		return 0;
	}
	printf("Current number of movements:%d\n", step);
	return (0);
}

int	close_game(int keycode, t_allimg *allimg)
{
	printf("close_game\n");
	if (keycode == 53)
		free_all(&allimg);
	return 0;
}
int	close_game_mouse(t_allimg *allimg)
{
	printf("mouse event\n");
	free_all(&allimg);
	return 0;
}

int main(int ac, char**av)
{
	t_map	map;
	static char	*g_map = 0;
	void	*mlx;
	void	*win;
	t_allimg *allimg;

	if (ac != 2 || check_extension(av[1], g_map))
		error_meg(0, ER_FILE, g_map);
	map = read_map(av[1], &g_map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 60 * map.col_curr, 60 * map.row, "Diamond Dig!");
	allimg = 0;
	initial_map(&map, mlx, win , &allimg, g_map);
	mlx_key_hook(win, &handle_input, &allimg);
	mlx_hook(win, 2, 1L<<0, &close_game, allimg);
	mlx_hook(win, 17, 1L<<0, &close_game_mouse, allimg);
	mlx_loop(mlx);
	
	return (0);
}