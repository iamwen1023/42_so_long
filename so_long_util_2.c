/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:27:17 by wlo               #+#    #+#             */
/*   Updated: 2021/09/30 12:29:32 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*
** # ifdef __APPLE__
** static void mlx_destroy_display(t_allimg **allimg)
** {
** 	free((*allimg)->mlx);
** 	(*allimg)->mlx = NULL;
** 	return ;
** }
** #endif
*/
void	free_all(t_allimg **allimg)
{
	mlx_destroy_image((*allimg)->m, (*allimg)->d);
	mlx_destroy_image((*allimg)->m, (*allimg)->e);
	mlx_destroy_image((*allimg)->m, (*allimg)->p);
	mlx_destroy_image((*allimg)->m, (*allimg)->f);
	mlx_destroy_image((*allimg)->m, (*allimg)->b);
	mlx_destroy_image((*allimg)->m, (*allimg)->ep);
	free((*allimg)->position);
	free((*allimg)->g_map);
	mlx_destroy_window((*allimg)->m, (*allimg)->w);
	if (OS)
		destroy((*allimg)->m);
	free((*allimg)->m);
	free((*allimg));
	exit(0);
}

int	check_gmap(char *g_map)
{
	int	i;
	int	collect;

	i = -1;
	collect = 0;
	while (g_map[++i])
	{
		if (g_map[i] == 'C')
			collect++;
	}
	return (collect);
}
