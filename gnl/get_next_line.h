/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:02:20 by mmayibo           #+#    #+#             */
/*   Updated: 2017/09/19 12:40:11 by gsebaets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 9

typedef struct			s_fd_list
{
	int					fd;
	char				*prevsaved;
	struct s_fd_list	*next;
}						t_fd_lst;
int						get_next_line(const int fd, char **line);
void					gnl_delete_lst_item(t_fd_lst **item, int fd);
#endif
