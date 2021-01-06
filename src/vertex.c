/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 23:12:23 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/06 16:32:27 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

int			ft_lstaddend(t_vertex **all, t_vertex *new)
{
	t_vertex	*temp;
	int num = 0;
	
	if (!new)
		return (0);
	temp = *all;
	if (!temp)
	{
		new->number = 0;
		*all = new;
	}
	else
	{
		while (temp->next)
		{
			num = temp->number;
			num++;
			temp = temp->next;
		}
		num++;
		new->number = num;
		temp->next = new;
	}
	return (1);
}

t_vertex	*new_vertex(int x, int y)
{
	t_vertex	*temp;

	temp = (t_vertex *)malloc(sizeof(t_vertex));
	temp->x = x; 
	temp->y = y;
	temp->next = NULL;
	return (temp);
}

void	draw_vertex(t_vertex *vertex, t_all *all, int i)
{
	SDL_Rect rect;
	t_vertex	*temp;
	
	temp = vertex;
	if (temp == NULL)
		return ;
	while(temp)
	{
		//SDL_SetRenderDrawColor(all->win.render, 0x42, 0x87, 0xf5, 0);
		rect = init_rect(temp->x - (i / 2), temp->y - (i / 2), i, i);
		SDL_RenderDrawRect(all->win.render, &rect);
		temp = temp->next;
	}
}