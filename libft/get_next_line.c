/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:57:38 by aghar             #+#    #+#             */
/*   Updated: 2020/11/14 17:57:40 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*cur;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	int				read_return;

	if (fd < 0 || !line || BUFF_SIZE < 1 || !(cur = ft_search_fd(&head, fd)))
		return (-1);
	if (ft_strchrend(cur->content) > -1)
		return (ft_putline(line, &cur));
	if (!(tmp = ft_strnew(0)))
		return (-1);
	while ((read_return = read(fd, buffer, BUFF_SIZE)))
	{
		if (read_return < 0)
			return (-1);
		buffer[read_return] = '\0';
		if (!(tmp = ft_strjoinfree(tmp, buffer, 0)))
			return (-1);
		if (ft_strchrend(tmp) > -1)
			break ;
	}
	cur->content = ft_strjoinfree(cur->content, tmp, 2);
	return ((read_return == 0 && (!cur->content || !((char *)cur->content)[0]))
		? 0 : ft_putline(line, &cur));
}

char				*ft_strjoinfree(char *s1, char *s2, int num)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	if (num == 0 || num == 2)
		ft_strdel(&s1);
	if (num == 1 || num == 2)
		ft_strdel(&s2);
	return (str);
}

int					ft_putline(char **line, t_list **cur)
{
	char			*tmp;
	int				mid;

	mid = ft_strchrend((*cur)->content);
	if ((*cur)->content)
		if (!(tmp = ft_strdup((*cur)->content)))
			return (-1);
	if (mid > -1)
	{
		*line = ft_strsub((*cur)->content, 0, (size_t)mid);
		ft_strdel((char **)&((*cur)->content));
		if (!((*cur)->content = ft_strsub(tmp,
			(unsigned int)mid + 1, ft_strlen(tmp) - (size_t)mid)))
			return (-1);
		ft_strdel(&tmp);
		return (1);
	}
	if ((*cur)->content)
		*line = ft_strdup((*cur)->content);
	ft_strdel((char **)&(*cur)->content);
	return (1);
}

int					ft_strchrend(const char *str)
{
	int				i;
	char			*rez;

	rez = (char *)str;
	i = 0;
	if (!str)
		return (-1);
	while (rez[i])
	{
		if (rez[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_list				*ft_search_fd(t_list **head, int fd)
{
	t_list			*cur;
	char			*str;

	cur = *head;
	while (cur)
	{
		if (cur->content_size == (size_t)fd)
			return (cur);
		cur = cur->next;
	}
	if (!(str = ft_strnew(0)))
		return (NULL);
	if (!(cur = ft_lstnew(str, 1)))
		return (NULL);
	ft_strdel(&str);
	cur->content_size = (size_t)fd;
	if (!*head)
		*head = cur;
	else
		ft_lstadd(head, cur);
	return (cur);
}
