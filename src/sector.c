/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:43:39 by spalmer           #+#    #+#             */
/*   Updated: 2020/12/12 23:28:08 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void		add_sector(t_all *all, t_sector *new)
{
	t_sector	*temp;

	if (all->level->sectors == NULL)
		all->level->sectors = new;
	else
	{
		new->next = all->level->sectors;
		all->level->sectors = new;
	}
	
}

t_sector	*new_sector(t_all *all)
{
	t_sector *new;

	new = (t_sector *)malloc(sizeof(t_sector));
	new->vertex = NULL;
	new->next = NULL;
	new->close = 0;
	return (new);
}