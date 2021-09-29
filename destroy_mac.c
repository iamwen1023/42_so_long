#include "includes/so_long.h"

void destroy(t_allimg **allimg)
{
	free((*allimg)->mlx);
	(*allimg)->mlx = NULL;
	return ;
}

