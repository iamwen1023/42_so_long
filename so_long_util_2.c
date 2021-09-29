#include "includes/so_long.h"

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
	if (OS)
		destroy((*allimg)->mlx);
	free((*allimg)->mlx);
	free((*allimg));
	exit(0);
}

int check_gmap(char *g_map)
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