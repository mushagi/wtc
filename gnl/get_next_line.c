/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:14:51 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/20 15:15:47 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd_lst				*fd_lstnew(int fd)
{
	t_fd_lst		*new;

	if (!(new = (t_fd_lst*)malloc(sizeof(t_fd_lst))))
		return (NULL);
	if (!(new->prevsaved = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static t_fd_lst				*get_file(int fd, t_fd_lst **fd_lst)
{
	t_fd_lst	*tmp;
	t_fd_lst	*item;

	tmp = *fd_lst;
	while (tmp)
	{
		item = tmp;
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = fd_lstnew(fd);
	item->next = tmp;
	return (item->next);
}

static int					ft_remalloc(char **prevsaved, int new_len)
{
	char	*temp;
	int		len;

	len = ft_strlen(*prevsaved);
	if (!(temp = ft_strdup(*prevsaved)))
		return (-1);
	ft_strdel(prevsaved);
	if (!(*prevsaved = ft_strnew(new_len + len)))
		return (-1);
	ft_strcat(*prevsaved, temp);
	ft_strdel(&temp);
	return (1);
}

static int					get_line(char **line, char **prevsaved, int ret)
{
	char	*temp;
	char	*temp_left;
	char	*start;
	int		len;

	len = ft_wordlen(*prevsaved, '\n');
	if (len == 0 && ret == 0 && ft_strlen(*prevsaved) == 0)
		return (0);
	temp = ft_strndup(*prevsaved, len);
	*line = temp;
	if (ft_strchr(*prevsaved, '\n'))
		start = *prevsaved + len + 1;
	else
		start = *prevsaved + len;
	if (!(temp_left = ft_strdup(start)))
		return (-1);
	ft_strdel(&*prevsaved);
	if (!(*prevsaved = ft_strnew(ft_strlen(temp_left))))
		return (-1);
	ft_strcpy(*prevsaved, temp_left);
	ft_strdel(&temp_left);
	return (1);
}

int							get_next_line(const int fd, char **line)
{
	static t_fd_lst		*fd_list;
	t_fd_lst			*file;
	char				*buff;
	int					ret;

	if (fd < 0)
		return (-1);
	if (!fd_list && !(fd_list = fd_lstnew(fd)))
		return (-1);
	file = get_file(fd, &fd_list);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0 || !ft_remalloc(&(file->prevsaved), ret))
			return (-1);
		ft_strncat(file->prevsaved, buff, ret);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if ((ret = get_line(line, &(file->prevsaved), ret)) == 0)
		gnl_delete_lst_item(&fd_list, fd);
	ft_strdel(&buff);
	return (ret);
}
