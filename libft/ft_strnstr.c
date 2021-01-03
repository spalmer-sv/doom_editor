/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 01:13:04 by aghar             #+#    #+#             */
/*   Updated: 2019/09/27 01:45:23 by aghar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (!*find)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0' && (size_t)pos < len)
	{
		if (str[pos] == find[0])
		{
			i = 1;
			while (find[i] != '\0' && str[pos + i] == find[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (find[i] == '\0')
				return ((char*)&str[pos]);
		}
		++pos;
	}
	return (0);
}
