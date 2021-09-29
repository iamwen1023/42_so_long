#include "includes/so_long.h"

void destroy(t_allimg **allimg)
{
	mlx_destroy_display((*allimg)->mlx);
	return ;
}