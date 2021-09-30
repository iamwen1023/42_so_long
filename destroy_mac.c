/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:42:15 by wlo               #+#    #+#             */
/*   Updated: 2021/09/30 12:42:51 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	destroy(t_allimg **allimg)
{
	free((*allimg)->m);
	(*allimg)->m = NULL;
	return ;
}