/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:00:11 by spalmer           #+#    #+#             */
/*   Updated: 2021/01/16 17:51:38 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	bresenham(int x0, int y0, int x1, int y1, t_all *all)
{
	int dx;
	int dy;
	int error;
	int error2;
	int sign_y;
	int sign_x;
	SDL_Rect pixel;
	
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	error = dx - dy;
	sign_x = x0 < x1 ? 1: -1;
	sign_y = y0 < y1 ? 1: -1;
	

	while (x0 != x1 || y0 != y1)
	{
		pixel = init_rect(x0, y0, 2, 2);
		SDL_RenderDrawRect(all->win.render, &pixel);
		error2 = error *2;
		if (error2 > -dy)
		{
			error -= dy;
			x0 += sign_x;
		}
		if (error2 < dx)
		{
			error += dx;
			y0 += sign_y;
		}
	}	
}

void	draw_one_sector(t_sector *sector, t_all *all, int color)
{
	t_vertex *temp;
	t_vertex first;
	t_vertex second;
	
	temp = sector->vertex; 
	if (sector->vertex == NULL)
		return ;
	if (!sector->vertex->next)
		return ;
	SDL_SetRenderDrawColor(all->win.render, color, color, color, 0);
	while(temp->next)
	{
		first.x = temp->x;
		first.y = temp->y;
		second.x = temp->next->x;
		second.y = temp->next->y;
		bresenham(first.x * all->setup.scale , first.y * all->setup.scale, second.x * all->setup.scale, second.y * all->setup.scale, all);
		temp = temp->next;
	}
}

void	draw_sectors(t_all *all)
{
	t_sector	*current;
	t_sector	*lower = NULL;
	
	current = all->level->sectors;
	if (all->lower_level)
		lower = all->lower_level->sectors;

	if (lower != NULL)
	{
		//printf("lower = %i\n", all->lower_level->num);
		while (lower)
		{
				draw_one_sector(lower, all, 100);
				lower = lower->next;
		}
	}

	while (current)
	{
		draw_one_sector(current, all, 255);
		current = current->next;
		//printf("print current");
	}
}
