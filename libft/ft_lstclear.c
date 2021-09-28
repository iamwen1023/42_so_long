/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:54:37 by wlo               #+#    #+#             */
/*   Updated: 2021/05/25 10:16:13 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temps;

	if (!(*lst))
		return ;
	current = (*lst);
	while (del && current->next != 0)
	{
		(*del)(current->content);
		temps = current->next;
		free(current);
		current = temps;
	}
	if (del)
		(*del)(current->content);
	free(current);
	(*lst) = 0;
}
