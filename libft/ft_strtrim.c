/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 01:14:56 by aghar             #+#    #+#             */
/*   Updated: 2019/09/27 02:21:15 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strstart(char *s, const char *isk)
{
	int				in;
	unsigned int	i;
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	i = 0;
	while (s[i])
	{
		in = 0;
		tmp = count;
		while (isk[in])
			if (isk[in++] == s[i])
				count++;
		if (count == tmp)
			return (count);
		i++;
	}
	return (count);
}

unsigned int	ft_strend(char *s, const char *isk)
{
	unsigned int	i;
	int				in;
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	i = (unsigned int)ft_strlen(s) - 1;
	while (s[i])
	{
		in = 0;
		tmp = count;
		while (isk[in])
			if (isk[in++] == s[i])
				++count;
		if (count == tmp)
			return (count);
		--i;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char			*res;
	unsigned int	start;
	unsigned int	size;
	unsigned int	spaces;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char*)s);
	spaces = ft_strstart((char*)s, " \n\t");
	start = spaces;
	if (size > spaces)
		spaces += ft_strend((char*)s, " \n\t");
	size -= spaces;
	if (!(res = ft_memalloc((size_t)size + 1)))
		return (NULL);
	res = ft_strncpy(res, (char*)s + start, size);
	return (res);
}
