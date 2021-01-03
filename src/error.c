/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:57:24 by spalmer           #+#    #+#             */
/*   Updated: 2020/11/27 21:40:49 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void		error(const char *str, int fd)
{
	if (!str)
		printf("Error Error\n");
	else
	{
		printf("Error ");
		printf("%s\n", str);
	}
	if (fd != 0)
		close(fd);
	exit(1);
}