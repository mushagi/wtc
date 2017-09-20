/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:23:16 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/20 15:01:10 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		gnl_delete_lst_item(t_fd_lst **item, int fd)
{
	t_fd_lst	*tmp;
	t_fd_lst	*iter;

	iter = *item;
	if (iter->fd == fd)
	{
		ft_strdel(&iter->prevsaved);
		*item = iter->next;
		ft_memdel((void **)&iter);
		return ;
	}
	while (iter)
	{
		tmp = iter->next;
		if (tmp)
		{
			if (tmp->fd == fd)
			{
				iter->next = tmp->next;
				ft_strdel(&tmp->prevsaved);
				ft_memdel((void **)&tmp);
			}
		}
		iter = iter->next;
	}
}
